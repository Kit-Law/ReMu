#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowIcon(QIcon("..\\GUIx86\\Resources\\Logo.png"));
    QPixmap logoPixMap("..\\GUIx86\\Resources\\ReMu-Full-Logo.png");
    ui->logo->setPixmap(logoPixMap.scaled(400, 400, Qt::KeepAspectRatio));

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_actionNew_triggered()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_actionOpen_triggered()));

    setupEditor();

    QMenu* editMenu = ui->textEdit->createStandardContextMenu();
    editMenu->setTitle("Edit");
    ui->menubar->addMenu(editMenu);

    QAction* settingsMenu = new QAction("Settings");
    connect(settingsMenu, SIGNAL(triggered()), this, SLOT(openSettingsDialog()));
    ui->menubar->addAction(settingsMenu);

    ui->tabWidget->tabBar()->hide();
    ui->textEdit->hide();

    configDialog = new ConfigDialog(&textSize, &themeFile, &cli, &musescore);
    connect(configDialog, &ConfigDialog::updateValues, this, &MainWindow::closeSettingsDialog);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupTabWidget()
{
    if (tabsetUp) return;
    tabsetUp = true;

    outputScore = new ScoreViewer(prevPage, nextPage, zoomIn, zoomOut);
    inputScore = new ScoreViewer(prevPage, nextPage, zoomIn, zoomOut);

    logText->setReadOnly(true);
    logText->setFontPointSize(11);

    ui->tabWidget->removeTab(0);
    ui->tabWidget->addTab(inputScore, "Input");
    ui->tabWidget->addTab(outputScore, "Output");
    ui->tabWidget->addTab(logText, "Log");

    QHBoxLayout* buttons = new QHBoxLayout();
    buttons->setSpacing(4);
    buttons->setContentsMargins(2, 0, 2, 0);

    connect(run, SIGNAL(clicked()), this, SLOT(runParser()));

    run->setEnabled(false);
    run->setText("Run");
    run->setIcon(QIcon("..\\GUIx86\\Resources\\run.png"));
    prevPage->setIcon(QIcon("..\\GUIx86\\Resources\\back.png"));
    nextPage->setIcon(QIcon("..\\GUIx86\\Resources\\next.png"));
    zoomIn->setIcon(QIcon("..\\GUIx86\\Resources\\zoom_in.png"));
    zoomOut->setIcon(QIcon("..\\GUIx86\\Resources\\zoom_out.png"));

    buttons->addWidget(run);
    buttons->addStretch();
    buttons->addWidget(prevPage);
    buttons->addWidget(nextPage);
    buttons->addWidget(zoomIn);
    buttons->addWidget(zoomOut);
    ui->splitter->handle(1)->setLayout(buttons);

    run->setEnabled(true);

    ui->tabWidget->tabBar()->show();
    ui->textEdit->show();
}

void MainWindow::setupEditor()
{
    highlighter = new SyntaxHighlighter(ui->textEdit->document());

    ui->textEdit->setTextColor(Qt::white);
    ui->textEdit->setTabStopDistance(20);

    QFont font;
    font.setPointSize(textSize);
    ui->textEdit->setFont(font);
    //ui->textEdit->setFontPointSize(textSize);
}

void MainWindow::on_actionNew_triggered() //TODO: Fix mem leak
{
    ProjectWindow* projectWindow = new ProjectWindow(this, &projectFile, &projectName, &inputFile, &outputFile, &inputScoreLoc, &outputScoreLoc, &logFile, &updateProjectDoc);

    QFile file(themeFile.c_str());
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    projectWindow->setStyleSheet(styleSheet);

    projectWindow->setAttribute(Qt::WA_DeleteOnClose);
    connect(projectWindow, SIGNAL(destroyed(QObject*)), this, SLOT(refresh()));
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Select Project File"), "", tr("XML (*.XML)"));
    projectFile = filename.toStdString().c_str();

    refresh();
}

void MainWindow::on_actionSave_As_triggered()
{
    if (projectFile == "")
        return;

    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (dir.isEmpty())
        return;

    std::filesystem::copy(projectFile.substr(0, projectFile.length() - 11), dir.toStdString() + "/" + projectName);
    //change all the elements
}

void MainWindow::on_actionChange_Input_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Select Input File"), "", tr("Music XML (*.MUSICXML)"));
    inputFile = filename.toStdString().c_str();

    if (inputFile.empty())
        return;

    on_actionSave_triggered();

    for (const auto& entry : std::filesystem::directory_iterator(inputScoreLoc))
        std::filesystem::remove_all(entry.path());
    for (const auto& entry : std::filesystem::directory_iterator(outputScoreLoc))
        std::filesystem::remove_all(entry.path());

    refresh();
}

void MainWindow::on_actionChange_Output_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Export"), "", tr("PDF (*.pdf);;MP3 (*.mp3)"));

    if (filename.isEmpty())
        return;

    std::string options = "\"" + outputFile + "\" -o \"" + filename.toStdString().c_str() + "\"";
    ShellExecuteA(NULL, "open", musescore.c_str(), options.c_str(), NULL, 0);
}

void updateProjectDoc(std::string* projectFile, std::string* projectName, std::string* inputFile, std::string* outputFile, std::string* inputScore, std::string* outputScore, std::string* logFile, const char* project)
{
    try
    {
        pugi::xml_document doc = openDoc(projectFile->c_str());

        doc.child("ProjectName").text().set(projectName->c_str());
        doc.child("InputFile").text().set(inputFile->c_str());
        doc.child("OutputFile").text().set(outputFile->c_str());
        doc.child("InputScore").text().set(inputScore->c_str());
        doc.child("OutputScore").text().set(outputScore->c_str());
        doc.child("LogFile").text().set(logFile->c_str());
        doc.child("Program").text().set(project);

        closeDoc(doc, projectFile->c_str());
    }
    catch(std::exception& e)
    { }
}

void MainWindow::on_actionSave_triggered()
{
    updateProjectDoc(&projectFile, &projectName, &inputFile, &outputFile, &inputScoreLoc, &outputScoreLoc, &logFile, ui->textEdit->toPlainText().toStdString().c_str());
}

void MainWindow::refresh()
{
    if (projectFile.empty())
        return;

    setupTabWidget();

    pugi::xml_document doc = openDoc(projectFile.c_str());

    projectName = doc.child("ProjectName").text().as_string();
    inputFile = doc.child("InputFile").text().as_string();
    outputFile = doc.child("OutputFile").text().as_string();
    inputScoreLoc = doc.child("InputScore").text().as_string();
    outputScoreLoc = doc.child("OutputScore").text().as_string();
    logFile = doc.child("LogFile").text().as_string();
    ui->textEdit->setText(doc.child("Program").text().as_string());

    closeDoc(doc, projectFile.c_str());

    std::string options = "\"" + inputFile + "\" -o \"" + inputScoreLoc + "\\temp.png\"";
    std::wstring stemp = std::wstring(options.begin(), options.end());
    std::wstring musescoreWStr = std::wstring(musescore.begin(), musescore.end());

    SHELLEXECUTEINFO ShExecInfo = { 0 };
    ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
    ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
    ShExecInfo.hwnd = NULL;
    ShExecInfo.lpVerb = NULL;
    ShExecInfo.lpFile = musescoreWStr.c_str();
    ShExecInfo.lpParameters = stemp.c_str();
    ShExecInfo.lpDirectory = NULL;
    ShExecInfo.nShow = SW_HIDE;
    ShExecInfo.hInstApp = NULL;
    ShellExecuteEx(&ShExecInfo);
    WaitForSingleObject(ShExecInfo.hProcess, INFINITE);
    CloseHandle(ShExecInfo.hProcess);

    if (ui->tabWidget->currentIndex() == 0)
    {
        outputScore->loadScores(QString::fromStdString(outputScoreLoc));
        inputScore->loadScores(QString::fromStdString(inputScoreLoc));
        inputScore->updateActions();
    }
    else
    {
        inputScore->loadScores(QString::fromStdString(inputScoreLoc));
        outputScore->loadScores(QString::fromStdString(outputScoreLoc));
        outputScore->updateActions();
    }

    run->setEnabled(true);
}

void MainWindow::runParser()
{
    outputScore->loadingBar();

    on_actionSave_triggered();;

    std::string options = '\"' + projectFile + '\"';
    std::wstring stemp = std::wstring(options.begin(), options.end());
    std::wstring cliWStr = std::wstring(cli.begin(), cli.end());

    SHELLEXECUTEINFO ShExecInfo = { 0 };
    ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
    ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
    ShExecInfo.hwnd = NULL;
    ShExecInfo.lpVerb = NULL;
    ShExecInfo.lpFile = cliWStr.c_str();
    ShExecInfo.lpParameters = stemp.c_str();
    ShExecInfo.lpDirectory = NULL;
    ShExecInfo.nShow = SW_HIDE;
    ShExecInfo.hInstApp = NULL;
    ShellExecuteEx(&ShExecInfo);
    WaitForSingleObject(ShExecInfo.hProcess, INFINITE);
    CloseHandle(ShExecInfo.hProcess);

    QFile logQFile(logFile.c_str());
    if (logQFile.open(QIODevice::ReadOnly | QIODevice::Text))
        logText->setText(QString(logQFile.readAll()));

    for (const auto& entry : std::filesystem::directory_iterator(outputScoreLoc))
        std::filesystem::remove_all(entry.path());

    options = "\"" + outputFile + "\" -o \"" + outputScoreLoc + "\\temp.png\"";
    stemp = std::wstring(options.begin(), options.end());
    std::wstring musescoreWStr = std::wstring(musescore.begin(), musescore.end());

    ShExecInfo = { 0 };
    ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
    ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
    ShExecInfo.hwnd = NULL;
    ShExecInfo.lpVerb = NULL;
    ShExecInfo.lpFile = musescoreWStr.c_str();
    ShExecInfo.lpParameters = stemp.c_str();
    ShExecInfo.lpDirectory = NULL;
    ShExecInfo.nShow = SW_HIDE;
    ShExecInfo.hInstApp = NULL;
    ShellExecuteEx(&ShExecInfo);
    WaitForSingleObject(ShExecInfo.hProcess, INFINITE);
    CloseHandle(ShExecInfo.hProcess);

    outputScore->loadScores(QString::fromStdString(outputScoreLoc));

    /*WorkerThread* workerThread = new WorkerThread();
    connect(workerThread, &WorkerThread::resultReady, this, &MainWindow::runParserThread);
    connect(workerThread, &WorkerThread::finished, workerThread, &QObject::deleteLater);
    workerThread->start();*/

    if (ui->tabWidget->currentIndex() == 0) inputScore->createActions();
    else if (ui->tabWidget->currentIndex() == 1) outputScore->createActions();
}

void MainWindow::runParserThread()
{
    
}

void MainWindow::openSettingsDialog()
{
    configDialog->exec();
}

void MainWindow::closeSettingsDialog()
{
    QFont font;
    font.setPointSize(textSize);
    ui->textEdit->setFont(font);
    //ui->textEdit->setFontPointSize(textSize);

    QFile file(themeFile.c_str());
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);
}