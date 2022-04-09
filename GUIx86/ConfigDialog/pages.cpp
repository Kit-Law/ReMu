#include <QtWidgets>

#include "pages.h"

ThemePage::ThemePage(int* textSizeNumber, std::string* themeFile, QWidget* parent)
    : QWidget(parent)
{
    this->textSizeNumber = textSizeNumber;
    this->themeFile = themeFile;

    QGroupBox* settings = new QGroupBox(tr("Settings"));

    QWidget* temp = new QWidget();
    QLabel* textSizeLabel = new QLabel(tr("Text Size"));
    textSize = new QSpinBox();
    textSize->setValue(*textSizeNumber);
    QHBoxLayout* textSizeLayout = new QHBoxLayout();
    textSizeLayout->addWidget(textSizeLabel);
    textSizeLayout->addWidget(textSize);
    temp->setLayout(textSizeLayout);

    QGroupBox* themeGroup = new QGroupBox(tr("Themes"));

    themeList->addItem(tr("Dark"));
    themeList->addItem(tr("Light"));
    themeList->setCurrentIndex(themeIndex);

    QVBoxLayout* settingsLayout = new QVBoxLayout;
    settingsLayout->addWidget(temp);
    settings->setLayout(settingsLayout);

    QVBoxLayout* themeLayout = new QVBoxLayout;
    themeLayout->addWidget(themeList);
    themeGroup->setLayout(themeLayout);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(settings);
    mainLayout->addWidget(themeGroup);
    mainLayout->addSpacing(12);
    setLayout(mainLayout);
}

void ThemePage::updateValues()
{
    *textSizeNumber = textSize->value();
    themeIndex = themeList->currentIndex();
    *themeFile = "..\\GUIx86\\Resources\\" + themeList->currentText().toStdString() + ".css";
}

ConfigurationPage::ConfigurationPage(std::string* cli, std::string* musescore, QWidget* parent)
    : QWidget(parent)
{
    this->cli = cli;
    this->musescore = musescore;

    QGroupBox* configGroup = new QGroupBox(tr("Exe configuration"));

    cliDir = new QLineEdit(cli->c_str());
    musescoreDir = new QLineEdit(musescore->c_str());

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(cliDir);
    layout->addWidget(musescoreDir);
    configGroup->setLayout(layout);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(configGroup);
    mainLayout->addStretch(1);
    setLayout(mainLayout);
}

void ConfigurationPage::updateValues()
{
    *cli = cliDir->text().toStdString();
    *musescore = musescoreDir->text().toStdString();
}