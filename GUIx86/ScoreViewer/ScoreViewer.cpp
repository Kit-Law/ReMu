#include <QtWidgets>

#include "ScoreViewer.h"

ScoreViewer::ScoreViewer(QToolButton* prevPageToolButton, QToolButton* nextPageToolButton, QToolButton* zoomInToolButton, QToolButton* zoomOutToolButton)
    : ui(new Ui::ImageViewer)
{
    ui->setupUi(this);

    scrollArea = ui->scrollArea;
    score = new QLabel("[Score needs to be generated]");

    score->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    score->setScaledContents(true);

    scrollArea->setWidget(score);

    this->prevPageToolButton = prevPageToolButton;
    this->nextPageToolButton = nextPageToolButton;
    this->zoomInToolButton = zoomInToolButton;
    this->zoomOutToolButton = zoomOutToolButton;

    createActions();
    updateActions();
}

void ScoreViewer::loadScores(const QString& dir)
{
    QImageReader reader;
    scores->clear();

    for (const auto& entry : std::filesystem::directory_iterator(dir.toStdString()))
    //for (int i = 1; true; i++)
    {
        //QString scoreFile = dir + "\\temp-" + (i + '0') + ".png";
        reader.setFileName(QString(entry.path().string().c_str()));
        const QImage newImage = reader.read();

        if (newImage.isNull())
            break;

        scores->push_back(newImage);
    }

    if (scores->size() == 0)
    {
        score->setText("[Score needs to be generated]");
        return;
    }

    currectScore = 0;
    setScore(currectScore);
}

void ScoreViewer::setScore(const size_t i)
{
    scorePixMap = QPixmap::fromImage(scores->at(i));
    scaleFactor = 0.3;
    score->setPixmap(scorePixMap.scaled(scaleFactor * scorePixMap.width(), scaleFactor * scorePixMap.height(), Qt::KeepAspectRatio));

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
    scaleImage(1.1);
}

void ScoreViewer::zoomOut()
{
    scaleImage(0.9);
}

void ScoreViewer::createActions()
{
    nextPageToolButton->disconnect();
    prevPageToolButton->disconnect();
    zoomInToolButton->disconnect();
    zoomOutToolButton->disconnect();

    connect(nextPageToolButton, SIGNAL(clicked()), this, SLOT(nextPage()));
    connect(prevPageToolButton, SIGNAL(clicked()), this, SLOT(prevPage()));
    connect(zoomInToolButton, SIGNAL(clicked()), this, SLOT(zoomIn()));
    connect(zoomOutToolButton, SIGNAL(clicked()), this, SLOT(zoomOut()));

    updateActions();
}

void ScoreViewer::updateActions()
{
    prevPageToolButton->setEnabled(currectScore != 0);
    nextPageToolButton->setEnabled(scores->size() != 0 && currectScore != scores->size() - 1);
    zoomInToolButton->setEnabled(scores->size() != 0);
    zoomOutToolButton->setEnabled(scores->size() != 0);
}

void ScoreViewer::scaleImage(double factor)
{
    Q_ASSERT(score->pixmap());
    scaleFactor *= factor;
    score->setPixmap(scorePixMap.scaled(scaleFactor * scorePixMap.width(), scaleFactor * scorePixMap.height(), Qt::KeepAspectRatio));

    adjustScrollBar(scrollArea->horizontalScrollBar(), factor);
    adjustScrollBar(scrollArea->verticalScrollBar(), factor);
}

void ScoreViewer::adjustScrollBar(QScrollBar* scrollBar, double factor)
{
    scrollBar->setValue(int(factor * scrollBar->value()
        + ((factor - 1) * scrollBar->pageStep() / 2)));
}

void ScoreViewer::loadingBar()
{
    //QMovie* movie = new QMovie("..\\GUIx86\\Resources\\loading-spinning.gif");
    //score->setMovie(movie);
    //score->show();
    //movie->start();

    score->setText("[Generating Score...]");
}