#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QPdfDocument>

#include <filesystem>
#include <fstream>  
#include <sstream>
#include <regex>

//#include "API.h"

#include "pugixml.hpp"

#include "SyntaxHighlighter.h"

#include "ProjectWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow* ui;
    SyntaxHighlighter* highlighter;

    QTabWidget* tabWidget;

    QPrinter* inputScore;

    std::string projectName;
    std::string projectFile;
    std::string inputFile;
    std::string outputFile;
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
private slots:
    void setupEditor();

    void on_actionNew_triggered();
    void on_actionOpen_triggered();

    void on_actionChange_Input_triggered();
    void on_actionChange_Output_triggered();
    void on_actionSave();
};

void updateProjectDoc(std::string* projectFile, std::string* projectName, std::string* inputFile, std::string* outputFile, const char* project);

inline pugi::xml_document openDoc(const char* input) //TODO: Remove this and use the one in CLI
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(input);
    if (!result)
        throw;

    return doc;
}

inline void closeDoc(pugi::xml_document& doc, const char* output)
{
    doc.save_file(output);
}
#endif // MAINWINDOW_H