#include <QtGui>

int main(int argc,char *argv[]){
    QApplication a(argc,argv);

    QWidget widget;
    widget.show();

    int x = widget.x();
    int y = widget.y();

    QRect geometry = widget.geometry();
    QRect frame = widget.frameGeometry();

    return a.exec();
}

int mainDemo1(int argc,char *argv[]){
    QApplication a(argc,argv);

    // ������ʹ�������ַ�
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    // �½� QWidget ����󣬶�������
    QWidget *widget = new QWidget(0,Qt::Dialog);
    widget->setWindowTitle(QObject::tr("����widget"));

    // �½� QLable����������
    QLabel *label = new QLabel(0,Qt::Dialog);
    label->setWindowTitle(QObject::tr("����label"));
    label->setText(QObject::tr("label:���Ǹ�����"));
    label->resize(180,20);

    // �½��Ӵ���
    QLabel *label2 = new QLabel(widget);
    label2->setText(QObject::tr("�Ҳ��Ƕ����Ĵ���"));
    label2->resize(250,20);

    // ����Ļ����ʾ����
    label->show();
    widget->show();

    int ret = a.exec();
    delete label;
    delete widget;
    return ret;
}
