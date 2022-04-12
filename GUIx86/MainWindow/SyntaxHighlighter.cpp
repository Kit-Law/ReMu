#include "SyntaxHighlighter.h"
#include <QTextCharFormat>
#include <QBrush>
#include <QColor>


SyntaxHighlighter::SyntaxHighlighter(QTextDocument* parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    sectionDefFormat.setFontWeight(QFont::Bold);
    sectionDefFormat.setForeground(QColor(QRgb(qRgb(242, 161, 80))));
    rule.pattern = QRegularExpression(QStringLiteral("\"[A-Za-z ]*\""));
    rule.format = sectionDefFormat;
    highlightingRules.append(rule);

    noteFormat.setForeground(QColor(QRgb(qRgb(255, 225, 122))));
    rule.pattern = QRegularExpression(QStringLiteral("([A-G](#|b)*(\[[0-9]+\])?(,| ))|(\[)|(\])"));
    rule.format = noteFormat;
    highlightingRules.append(rule);

    wordFormat.setFontWeight(QFont::StyleItalic);
    wordFormat.setForeground(QColor(QRgb(qRgb(255, 225, 122))));
    rule.pattern = QRegularExpression(QStringLiteral("[a-zA-Z]+( |,)"));
    rule.format = wordFormat;
    highlightingRules.append(rule);

    transitionFormat.setFontWeight(QFont::Bold);
    transitionFormat.setForeground(QColor(QRgb(qRgb(242, 161, 80))));
    rule.pattern = QRegularExpression(QStringLiteral("->"));
    rule.format = transitionFormat;
    highlightingRules.append(rule);
    
    scaleFormat.setFontWeight(QFont::Bold);
    scaleFormat.setForeground(QColor(QRgb(qRgb(255, 225, 122))));
    rule.pattern = QRegularExpression(QStringLiteral("(Scale:)"));
    rule.format = scaleFormat;
    highlightingRules.append(rule);

    instrumentFormat.setFontWeight(QFont::Bold);
    instrumentFormat.setForeground(QColor(QRgb(qRgb(144, 195, 209))));
    rule.pattern = QRegularExpression(QStringLiteral("^((?!((addScale)|(addChord))).)*{$|^((?![0-9,{]).)*}$"));
    rule.format = instrumentFormat;
    highlightingRules.append(rule);

    qualityFormat.setForeground(QColor(QRgb(qRgb(255, 171, 174))));
    rule.pattern = QRegularExpression(QStringLiteral("(maj( |,))|(min( |,))|(dim( |,))|(aug( |,))|(alt( |,))|(sus( |,))|(add( |,))|(omit( |,))|([0-9]+)"));
    rule.format = qualityFormat;
    highlightingRules.append(rule);

    commandFormat.setFontWeight(QFont::Bold);
    commandFormat.setForeground(QColor(QRgb(qRgb(204, 86, 139))));
    rule.pattern = QRegularExpression(QStringLiteral("(addScale( )*[a-zA-Z]*)|(addChord( )*[a-zA-Z]*)"));
    rule.format = commandFormat;
    highlightingRules.append(rule);

    messureFormat.setFontWeight(QFont::StyleItalic);
    messureFormat.setForeground(QColor(QRgb(qRgb(242, 161, 80))));
    rule.pattern = QRegularExpression(QStringLiteral("(\\b[0-9]+( )*-( )*[0-9]+)"));
    rule.format = messureFormat;
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