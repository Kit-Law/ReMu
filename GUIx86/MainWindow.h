#pragma once

#include <QMainWindow>
#include <QFileDialog>
#include <QToolButton>
#include <QTabBar>

#include <direct.h>
#include <fstream>  
#include <sstream>
#include <regex>

#include <iostream>
#include <windows.h>

#include "ui_mainwindow.h"

#include "pugixml.hpp"

#include "SyntaxHighlighter.h"
#include "ProjectWindow.h"

#include "ScoreViewer.h"

#include <QGraphicsScene>
#include <QGraphicsView>

#include <sys/stat.h>

//#include "API.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow* ui;
    SyntaxHighlighter* highlighter;

    ScoreViewer* inputScore;
    ScoreViewer* outputScore;

    QToolButton* run = new QToolButton();
    QToolButton* prevPage = new QToolButton();
    QToolButton* nextPage = new QToolButton();
    QToolButton* zoomIn = new QToolButton();
    QToolButton* zoomOut = new QToolButton();

    std::string projectName;
    std::string projectFile;
    std::string inputFile;
    std::string outputFile;
    std::string inputScoreLoc;
    std::string outputScoreLoc;
public:
    MainWindow(QWidget *parent = Q_NULLPTR);
    ~MainWindow();

    void updateSizes();
private slots:
    void setupEditor();

    void on_actionNew_triggered();
    void on_actionOpen_triggered();

    void on_actionChange_Input_triggered();
    void on_actionChange_Output_triggered();
    void on_actionSave_triggered();

    void on_tabWidget_currentChanged(int index)
    {
        if (index == 0) inputScore->createActions();
        else if (index == 1) outputScore->createActions();
    }

    void runParser();
};

void updateProjectDoc(std::string* projectFile, std::string* projectName, std::string* inputFile, std::string* outputFile, std::string* inputScore, std::string* outputScore, const char* project);

inline pugi::xml_document openDoc(const char* input) //TODO: Remove this and use the one in CLI
{
    if (std::string(input) == "")
        throw std::exception("No file selected");

    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(input);
    if (!result)
        throw std::exception("File not found");

    return doc;
}

inline void closeDoc(pugi::xml_document& doc, const char* output)
{
    doc.save_file(output);
}