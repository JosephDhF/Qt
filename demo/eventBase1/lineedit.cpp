#include "lineedit.h"

#include <QKeyEvent>
#include <QDebug>

lineEdit::lineEdit(QWidget *parent) :
    QLineEdit(parent)
{
}

void lineEdit::keyPressEvent(QKeyEvent *event)
{

    qDebug()<<tr("LineEdit ���̱����")<<event->text();
    //ִ��QLineEdit���Ĭ�ϴ���
    QLineEdit::keyPressEvent(event);
    event->ignore();//��������ԣ��¼�����ð�ݳ�ȥ
}

bool lineEdit::event(QEvent *event)
{
    if (event->type() == QEvent::KeyPress)
        qDebug()<<tr("lineEdit �� event() ����");
    return QLineEdit::event(event);
}
