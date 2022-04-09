#ifndef PAGES_H
#define PAGES_H

#include <QWidget>

class ThemePage : public QWidget
{
private:
    int* textSizeNumber;
    int themeIndex = 0;
    std::string* themeFile;

    QSpinBox* textSize;
    QComboBox* themeList = new QComboBox;
public:
    ThemePage(int* textSizeNumber, std::string* themeFile, QWidget* parent = 0);

    void updateValues();

    inline std::string* getThemeFile() { return themeFile; }
};

class ConfigurationPage : public QWidget
{
private:
    std::string* cli;
    std::string* musescore;

    QLineEdit* cliDir;
    QLineEdit* musescoreDir;
public:
    ConfigurationPage(std::string* cli, std::string* musescore, QWidget* parent = 0);

    void updateValues();
};

#endif