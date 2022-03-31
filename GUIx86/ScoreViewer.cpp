#include <QtWidgets>

#include "ScoreViewer.h"

ScoreViewer::ScoreViewer()
    : ui(new Ui::ImageViewer)
{
    ui->setupUi(this);

    scrollArea = ui->scrollArea;
    score = new QLabel();

    score->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    score->setScaledContents(true);

    scrollArea->setWidget(score);

    createActions();
    updateActions();

    //resize(QGuiApplication::primaryScreen()->availableSize() * 3 / 5);
}

void ScoreViewer::loadScores(const QString& dir)
{
    QImageReader reader;
    scores.clear();

    for (int i = 1; true; i++)
    {
        QString scoreFile = dir + "\\temp-" + (i + '0') + ".png";
        reader.setFileName(scoreFile);
        const QImage newImage = reader.read();

        if (newImage.isNull())
            break;

        scores.push_back(newImage);
    }

    if (scores.size() == 0)
        return;

    currectScore = 0;
    setScore(currectScore);

    updateActions();
}

void ScoreViewer::setScore(const size_t i)
{
    score->setPixmap(QPixmap::fromImage(scores[i]));
    scaleFactor = 1.0;

    score->adjustSize();
}

void ScoreViewer::nextPage()
{
    currectScore++;
    setScore(currectScore);

    updateActions();
}

void ScoreViewer::prevPage()
{
    currectScore--;
    setScore(currectScore);

    updateActions();
}

void ScoreViewer::zoomIn()
{
    scaleImage(1.25);
}

void ScoreViewer::zoomOut()
{
    scaleImage(0.8);
}

void ScoreViewer::normalSize()
{
    score->adjustSize();
    scaleFactor = 1.0;
}

void ScoreViewer::createActions()
{
    connect(ui->nextPage, SIGNAL(clicked()), this, SLOT(nextPage()));
    connect(ui->prevPage, SIGNAL(clicked()), this, SLOT(prevPage()));
    connect(ui->zoomIn, SIGNAL(clicked()), this, SLOT(zoomIn()));
    connect(ui->zoomOut, SIGNAL(clicked()), this, SLOT(zoomOut()));
}

void ScoreViewer::updateActions()
{
    ui->prevPage->setEnabled(currectScore != 0);
    ui->nextPage->setEnabled(scores.size() != 0 && currectScore != scores.size() - 1);
}

void ScoreViewer::scaleImage(double factor)
{
    Q_ASSERT(score->pixmap());
    scaleFactor *= factor;
    score->resize(scaleFactor * score->pixmap()->size());

    adjustScrollBar(scrollArea->horizontalScrollBar(), factor);
    adjustScrollBar(scrollArea->verticalScrollBar(), factor);

    //zoomInAct->setEnabled(scaleFactor < 3.0);
    //zoomOutAct->setEnabled(scaleFactor > 0.333);
}

void ScoreViewer::adjustScrollBar(QScrollBar* scrollBar, double factor)
{
    scrollBar->setValue(int(factor * scrollBar->value()
        + ((factor - 1) * scrollBar->pageStep() / 2)));
}