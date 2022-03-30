#include "ProjectWindow.h"
#include "ui_projectwindow.h"

ProjectWindow::ProjectWindow(QWidget* parent, std::string* projectFile, std::string* projectName, std::string* inputFile, std::string* outputFile,
        void (*save) (std::string*, std::string*, std::string*, std::string*, const char*))
    : QDialog(parent)
    , ui(new Ui::ProjectWindow)
{
    ui->setupUi(this);

    connect(ui->openInput, SIGNAL(clicked()), this, SLOT(on_actionChange_Input_triggered()));
    connect(ui->setOutput, SIGNAL(clicked()), this, SLOT(on_actionChange_Output_triggered()));
    connect(ui->create, SIGNAL(clicked()), this, SLOT(on_actionCreate()));
    connect(ui->cancel, SIGNAL(clicked()), this, SLOT(on_actionClose()));

    this->projectFile = projectFile;
    this->projectName = projectName;
    this->inputFile = inputFile;
    this->outputFile = outputFile;

    this->save = save;

    this->show();
}

ProjectWindow::~ProjectWindow()
{ 
    delete ui;
}

void ProjectWindow::on_actionChange_Input_triggered()
{
    QString filename = QFileDialog::getOpenFileName((QWidget*) this->parent(), tr("Select Input File"), "", tr("Music XML (*.MUSICXML)"));

    ui->input->setText(filename.toStdString().c_str());
}

void ProjectWindow::on_actionChange_Output_triggered()
{
    QString filename = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    ui->output->setText(filename.toStdString().c_str());
}

void ProjectWindow::on_actionCreate()
{
    *projectName = ui->name->text().toStdString();

    std::string outputDir = (ui->output->text().toStdString() + "/" + *projectName);

    *projectFile = outputDir + "/Project.xml";
    *inputFile = ui->input->text().toStdString();
    *outputFile = outputDir + "/Output.MUSICXML";

    const char* program = "";

    setupProjectDoc(&outputDir);
    (*save)(projectFile, projectName, inputFile, outputFile, program);
    
    on_actionClose();
}

void ProjectWindow::on_actionClose()
{
    this->~ProjectWindow();
}

void ProjectWindow::setupProjectDoc(std::string* outputDir)
{
    //std::filesystem::create_directories(outputDir->c_str());

    pugi::xml_document doc;

    doc.append_child("ProjectName");
    doc.append_child("InputFile");
    doc.append_child("OutputFile");
    doc.append_child("Program");

    doc.save_file((*outputDir + "/Project.xml").c_str());
}