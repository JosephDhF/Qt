#ifndef SYNTAXHIGHLIGHTER_H
#define SYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>

class SyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    // ���뽫 QObject �޸�Ϊ QTextDocument ����������
    explicit SyntaxHighlighter(QTextDocument *parent);

protected:
    // ��������ʵ�ָú���
    void highlightBlock(const QString &text);

signals:

public slots:

};

#endif // SYNTAXHIGHLIGHTER_H
