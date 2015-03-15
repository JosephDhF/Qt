#include <QtGui/QApplication>
#include "mywidget.h"
#include <QTextCodec>

#include "mydialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    MyWidget w;
    MyDialog dialog;
    if (dialog.exec() == QDialog::Accepted){//�ж� dialog ִ��Ч��
        w.show();
        return a.exec();
    }
    else return 0;
}
