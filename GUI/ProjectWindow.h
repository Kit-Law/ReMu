#ifndef PROJECTWINDOW_H
#define PROJECTWINDOW_H

#include <QDialog>
#include <QFileDialog>

#include "ui_projectWindow.h"

#include "pugixml.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class ProjectWindow; }
QT_END_NAMESPACE

class ProjectWindow : public QDialog
{
    Q_OBJECT
private:
    Ui::ProjectWindow* ui;

    std::string* projectFile;
    std::string* projectName;
    std::string* inputFile;
    std::string* outputFile;

    void (*save) (std::string*, std::string*, std::string*, std::string*, const char*);
public:
    ProjectWindow(QWidget* parent, std::string* projectFile, std::string* projectName, std::string* inputFile, std::string* outputFile,
        void (*save) (std::string*, std::string*, std::string*, std::string*, const char*));
    ~ProjectWindow();
private slots:
    void on_actionChange_Input_triggered();
    void on_actionChange_Output_triggered();
    void on_actionClose();
    void on_actionCreate();
private:
    void setupProjectDoc(std::string* outputDir);
};
#endif