#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    inputScore = new ScoreViewer();
    outputScore = new ScoreViewer();

    ui->tabWidget->removeTab(0);
    ui->tabWidget->addTab(inputScore, "Input");
    ui->tabWidget->addTab(outputScore, "Output");

    setupEditor();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupEditor()
{
    highlighter = new SyntaxHighlighter(ui->textEdit->document());

    ui->textEdit->setTextColor(Qt::white);
}

void MainWindow::on_actionNew_triggered() //TODO: Fix mem leak
{
    new ProjectWindow(this, &projectFile, &projectName, &inputFile, &outputFile, &updateProjectDoc);
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Select Project File"), "", tr("XML (*.XML)"));

    projectFile = filename.toStdString().c_str();

    pugi::xml_document doc = openDoc(projectFile.c_str());

    projectName = doc.child("ProjectName").text().as_string();
    inputFile = doc.child("InputFile").text().as_string();
    outputFile = doc.child("OutputFile").text().as_string();
    inputScoreLoc = doc.child("InputScore").text().as_string();
    outputScoreLoc = doc.child("OutputScore").text().as_string();
    ui->textEdit->setText(doc.child("Program").text().as_string());

    closeDoc(doc, projectFile.c_str());

    std::string options = "\"" + inputFile + "\" -o \"" + inputScoreLoc + "\\temp\"";
    ShellExecuteA(NULL, "open", "D:\\Program\ Files\\MuseScore\ 3\\bin\\MuseScore3.exe", options.c_str(), NULL, 0);

    //inputScore->loadFile(QString::fromStdString(inputScoreLoc));
    inputScore->loadScores(QString::fromStdString(inputScoreLoc));
}

void MainWindow::on_actionChange_Input_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Select Input File"), "", tr("Music XML (*.MUSICXML)"));

    inputFile = filename.toStdString().c_str();
}

void MainWindow::on_actionChange_Output_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Set Output File"), "", tr("Music XML (*.MUSICXML)"));

    outputFile = filename.toStdString().c_str();
}

void updateProjectDoc(std::string* projectFile, std::string* projectName, std::string* inputFile, std::string* outputFile, std::string* inputScore, std::string* outputScore, const char* project)
{
    try
    {
        pugi::xml_document doc = openDoc(projectFile->c_str());

        doc.child("ProjectName").text().set(projectName->c_str());
        doc.child("InputFile").text().set(inputFile->c_str());
        doc.child("OutputFile").text().set(outputFile->c_str());
        doc.child("InputScore").text().set(inputScore->c_str());
        doc.child("OutputScore").text().set(outputScore->c_str());
        doc.child("Program").text().set(project);

        closeDoc(doc, projectFile->c_str());
    }
    catch(std::exception& e)
    { }
}

void MainWindow::on_actionSave_triggered()
{
    updateProjectDoc(&projectFile, &projectName, &inputFile, &outputFile, &inputScoreLoc, &outputScoreLoc, ui->textEdit->toPlainText().toStdString().c_str());

    std::string pojectFileOption = '\"' + projectFile + '\"';
    ShellExecuteA(NULL, "open", "U:\\3rd\ Yr\ Project\\ReMu\\Debug\\CLI.exe", pojectFileOption.c_str(), NULL, 0);

    std::string options = "\"" + outputFile + "\" -o \"" + outputScoreLoc +"\\temp.png\"";
    ShellExecuteA(NULL, "open", "D:\\Program\ Files\\MuseScore\ 3\\bin\\MuseScore3.exe", options.c_str(), NULL, 0);

    outputScore->loadScores(QString::fromStdString(outputScoreLoc));
}