#include "widget.h"
#include "ui_widget.h"
#include "mybutton.h"
#include <QDebug>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    mybutton *button = new mybutton(this);
    button->setText(tr("button"));

    mybutton *button2 = new mybutton;
    mybutton *button3 = new mybutton;
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(button2);
    layout->addWidget(button3);
    // �ڸô�����ʹ�ò��ֹ�����
    setLayout(layout);

    //��������Ӳ������б�Ŀ�ģ��鿴 layout ���Ӳ����Ƿ��Զ�ת
    //Ϊ��ǰ���ڵ��Ӳ���
    qDebug()<<children();
}

Widget::~Widget()
{
    delete ui;
    qDebug()<<"delete widget";
}
