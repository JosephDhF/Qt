#include "syntaxhighlighter.h"

SyntaxHighlighter::SyntaxHighlighter(QTextDocument *parent) :
    QSyntaxHighlighter(parent)
{
}

void SyntaxHighlighter::highlightBlock(const QString &text)
{
    //�ַ���ʽ
    QTextCharFormat format;
    format.setFontWeight(QFont::Bold);
    format.setForeground(Qt::green);
    QString pattern = "\\bchar\\b";

    QRegExp expression(pattern);//����һ��������ʽ

    int index = text.indexOf(expression);
    // ���ƥ��ɹ�����ô����ֵΪ�ַ�������ʼλ�ã������ڻ����0
    while(index >= 0){
        int length = expression.matchedLength();//Ҫƥ����ַ�������
        setFormat(index,length,format);
        index = text.indexOf(expression,index+length);//����ƥ��
    }
}
