#include <QtGui/QApplication>
#include "mywidget.h"
#include <QTextCodec>

// Qt ʾ������Standard Dialogs

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    MyWidget w;
    w.show();

    return a.exec();
}
