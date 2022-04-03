#pragma once

#include <QThread>

class WorkerThread : public QThread
{
    Q_OBJECT
        void run() override {
        QString result;
        /* ... here is the expensive or blocking operation ... */
        emit resultReady(result);
    }
signals:
    void resultReady(const QString& s);
};