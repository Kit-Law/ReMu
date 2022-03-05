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
    ui->textEdit->setText(doc.child("Program").text().as_string());

    closeDoc(doc, projectFile.c_str());
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

void updateProjectDoc(std::string* projectFile, std::string* projectName, std::string* inputFile, std::string* outputFile, const char* project)
{
    pugi::xml_document doc = openDoc(projectFile->c_str());

    doc.child("ProjectName").text().set(projectName->c_str());
    doc.child("InputFile").text().set(inputFile->c_str());
    doc.child("OutputFile").text().set(outputFile->c_str());
    doc.child("Program").text().set(project);

    closeDoc(doc, projectFile->c_str());
}

void MainWindow::on_actionSave()
{
    updateProjectDoc(&projectFile, &projectName, &inputFile, &outputFile, ui->textEdit->toPlainText().toStdString().c_str());
    
    //ReMu::Listener* listener = ReMu::API::parse(ss);
    //ReMu::API::eval(listener, inputFile, outputFile);
}