#pragma once

#include <QRegularExpression>
#include <QSyntaxHighlighter>

QT_BEGIN_NAMESPACE
class QTextDocument;
class QTextCharFormat;
QT_END_NAMESPACE

class SyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    explicit SyntaxHighlighter(QTextDocument* parent = 0);

protected:
    void highlightBlock(const QString& text) Q_DECL_OVERRIDE;

private:
    struct HighlightingRule
    {
        QRegularExpression pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

    QTextCharFormat sectionDefFormat;
    QTextCharFormat wordFormat;
    QTextCharFormat messureFormat;
    QTextCharFormat transitionFormat;
    QTextCharFormat noteFormat;
    QTextCharFormat scaleFormat;
    QTextCharFormat commandFormat;
    QTextCharFormat qualityFormat;
    QTextCharFormat commentFormat;
    QTextCharFormat instrumentFormat;
};