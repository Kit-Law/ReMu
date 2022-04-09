#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>
#include <QtWidgets>

#include "pages.h"

class QListWidget;
class QListWidgetItem;
class QStackedWidget;

class ConfigDialog : public QDialog
{
    Q_OBJECT

public:
    ConfigDialog(int* textSize, std::string* themeFile, std::string* cli, std::string* musescore);
    void updateSignal();

public slots:
    void changePage(QListWidgetItem* current, QListWidgetItem* previous);

private:
    void createIcons();

    QListWidget* contentsWidget;
    QStackedWidget* pagesWidget;

    ConfigurationPage* configPage;
    ThemePage* themePage;
    
signals:
    void updateValues();
};

#endif