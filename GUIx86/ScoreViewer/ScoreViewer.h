#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QScrollArea>
#include <QImage>
#include <QToolButton>
#include <QMovie>

#include <vector>

#include <filesystem>

#include "ui_ImageViewer.h"

class QAction;
class QLabel;
class QMenu;
class QScrollArea;
class QScrollBar;

QT_BEGIN_NAMESPACE
namespace Ui { class ImageViewer; }
QT_END_NAMESPACE

class ScoreViewer : public QWidget
{
    Q_OBJECT

private:
    Ui::ImageViewer* ui;

    QLabel* score;
    QScrollArea* scrollArea;

    std::vector<QImage>* scores = new std::vector<QImage>();
    QPixmap scorePixMap;
    size_t currectScore = 0;
    double scaleFactor = 1.0;

    QAction* zoomInAct;
    QAction* zoomOutAct;
    QAction* normalSizeAct;

    QToolButton* prevPageToolButton;
    QToolButton* nextPageToolButton;
    QToolButton* zoomInToolButton;
    QToolButton* zoomOutToolButton;
public:
    ScoreViewer(QToolButton* prevPageToolButton, QToolButton* nextPageToolButton, QToolButton* zoomInToolButton, QToolButton* zoomOutToolButton);
    //~ScoreViewer() { delete score; delete scrollArea; delete scores; delete zoomInAct; delete zoomOutAct; delete normalSizeAct; delete prevPageToolButton;
    //        delete nextPageToolButton; delete zoomInToolButton; delete zoomOutToolButton; }

    void loadScores(const QString& dir);

    void createActions();
    void updateActions();

    void loadingBar();
private slots:
    void nextPage();
    void prevPage();
    void zoomIn();
    void zoomOut();
private:
    void setScore(const size_t i);
    
    void scaleImage(double factor);
    void adjustScrollBar(QScrollBar* scrollBar, double factor);
};

#endif