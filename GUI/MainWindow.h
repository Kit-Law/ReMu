#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

#include <sstream>

//#include "API.h"

#include "SyntaxHighlighter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow* ui;
    SyntaxHighlighter* highlighter;

    const char* inputFile;
    const char* outputFile;
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
private slots:
    void setupEditor();

    void on_actionNew_Project_triggered();
    void on_actionOpen_Project();
    void on_actionSave();
};
#endif // MAINWINDOW_H