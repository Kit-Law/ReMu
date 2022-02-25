#include "MainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

void MainWindow::on_actionNew_Project_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Select Input File"), "", tr("Music XML (*.MUSICXML)"));

    inputFile = filename.toStdString().c_str();
}

void MainWindow::on_actionOpen_Project()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Set Output File"), "", tr("Music XML (*.MUSICXML)"));

    outputFile = filename.toStdString().c_str();
}

void MainWindow::on_actionSave()
{
    std::stringstream ss;
    ss << ui->textEdit->toPlainText().toStdString();

    //ReMu::Listener* listener = ReMu::API::parse(ss);
    //ReMu::API::eval(listener, inputFile, outputFile);
}