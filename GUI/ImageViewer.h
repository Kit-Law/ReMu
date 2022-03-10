#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QMainWindow>
#include <QImage>

class QAction;
class QLabel;
class QMenu;
class QScrollArea;
class QScrollBar;

class ImageViewer : public QWidget
{
    Q_OBJECT

public:
    ImageViewer(QMainWindow* __parent);
    bool loadFile(const QString&);

private slots:
    void open();
    void saveAs();
    void print();
    void copy();
    void paste();
    void zoomIn();
    void zoomOut();
    void normalSize();
    void fitToWindow();
    void about();

private:
    void createActions();
    void createMenus();
    void updateActions();
    bool saveFile(const QString& fileName);
    void setImage(const QImage& newImage);
    void scaleImage(double factor);
    void adjustScrollBar(QScrollBar* scrollBar, double factor);

    QMainWindow* parent;

    QImage image;
    QLabel* imageLabel;
    QScrollArea* scrollArea;
    double scaleFactor;

    QAction* saveAsAct;
    QAction* printAct;
    QAction* copyAct;
    QAction* zoomInAct;
    QAction* zoomOutAct;
    QAction* normalSizeAct;
    QAction* fitToWindowAct;
};

#endif