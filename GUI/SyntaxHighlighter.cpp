#include "SyntaxHighlighter.h"
#include <QTextCharFormat>
#include <QBrush>
#include <QColor>


SyntaxHighlighter::SyntaxHighlighter(QTextDocument* parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    sectionDefFormat.setFontWeight(QFont::Bold);
    sectionDefFormat.setForeground(QColor(QRgb(qRgb(144, 195, 209))));
    rule.pattern = QRegularExpression(QStringLiteral("\"[A-Za-z\n( )]*\""));
    rule.format = sectionDefFormat;
    highlightingRules.append(rule);

    messureFormat.setFontWeight(QFont::StyleItalic);
    messureFormat.setForeground(QColor(QRgb(qRgb(242, 161, 80))));
    rule.pattern = QRegularExpression(QStringLiteral("\\b[0-9]+( )*-( )*[0-9]+"));
    rule.format = messureFormat;
    highlightingRules.append(rule);

    transitionFormat.setFontWeight(QFont::Bold);
    transitionFormat.setForeground(QColor(QRgb(qRgb(219, 132, 218))));
    rule.pattern = QRegularExpression(QStringLiteral("->"));
    rule.format = transitionFormat;
    highlightingRules.append(rule);

    noteFormat.setForeground(QColor(QRgb(qRgb(255, 238, 181))));
    rule.pattern = QRegularExpression(QStringLiteral("[A-G](#|b)* "));
    rule.format = noteFormat;
    highlightingRules.append(rule);
    
    commentFormat.setForeground(Qt::gray);
    rule.pattern = QRegularExpression(QStringLiteral("//[^\n]*"));
    rule.format = commentFormat;
    highlightingRules.append(rule);
}

void SyntaxHighlighter::highlightBlock(const QString& text)
{
    for (const HighlightingRule& rule : qAsConst(highlightingRules)) 
    {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) 
        {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }

    setCurrentBlockState(0);
}