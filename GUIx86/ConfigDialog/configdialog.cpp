#include "configdialog.h"

ConfigDialog::ConfigDialog(int* textSize, std::string* themeFile, std::string* cli, std::string* musescore)
{
    setWindowIcon(QIcon("..\\GUIx86\\Resources\\Logo.png"));

    contentsWidget = new QListWidget;
    contentsWidget->setViewMode(QListView::IconMode);
    contentsWidget->setIconSize(QSize(80, 100));
    contentsWidget->setMovement(QListView::Static);
    contentsWidget->setMaximumWidth(128);
    contentsWidget->setSpacing(12);

    themePage = new ThemePage(textSize, themeFile, this);
    configPage = new ConfigurationPage(cli, musescore, this);

    pagesWidget = new QStackedWidget;
    pagesWidget->addWidget(themePage);
    pagesWidget->addWidget(configPage);

    QPushButton* closeButton = new QPushButton(tr("Close"));
    QPushButton* updateButton = new QPushButton(tr("Save"));

    createIcons();
    contentsWidget->setCurrentRow(0);

    connect(updateButton, &QAbstractButton::clicked, this, &ConfigDialog::updateSignal);
    connect(closeButton, &QAbstractButton::clicked, this, &QDialog::close);

    QHBoxLayout* horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(contentsWidget);
    horizontalLayout->addWidget(pagesWidget, 1);

    QHBoxLayout* buttonsLayout = new QHBoxLayout;
    buttonsLayout->addStretch(1);
    buttonsLayout->addWidget(updateButton);
    buttonsLayout->addWidget(closeButton);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(horizontalLayout);
    mainLayout->addStretch(1);
    mainLayout->addSpacing(12);
    mainLayout->addLayout(buttonsLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Config Dialog"));
    QFile file(themePage->getThemeFile()->c_str());
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    this->setStyleSheet(styleSheet);
}

void ConfigDialog::createIcons()
{
    QListWidgetItem* themeButton = new QListWidgetItem(contentsWidget);
    themeButton->setText(tr("Theme"));
    themeButton->setTextAlignment(Qt::AlignHCenter);
    themeButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem* configButton = new QListWidgetItem(contentsWidget);
    configButton->setText(tr("Configuration"));
    configButton->setTextAlignment(Qt::AlignHCenter);
    configButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    connect(contentsWidget, &QListWidget::currentItemChanged, this, &ConfigDialog::changePage);
}

void ConfigDialog::changePage(QListWidgetItem* current, QListWidgetItem* previous)
{
    if (!current)
        current = previous;

    pagesWidget->setCurrentIndex(contentsWidget->row(current));
}

void ConfigDialog::updateSignal()
{
    themePage->updateValues();
    configPage->updateValues();

    QFile file(themePage->getThemeFile()->c_str());
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    this->setStyleSheet(styleSheet);

    emit updateValues();
    close();
}