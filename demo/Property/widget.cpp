#include "widget.h"
#include "ui_widget.h"
#include "myclass.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    MyClass *my = new MyClass(this);
    connect(my,
            SIGNAL(userNameChanged(QString)),
            this,
            SLOT(userChanged(QString)));
    //�޸����Ե�ֵ
    my->setUserName("yafei");
    qDebug()<<"userName:"<<my->getUserName();

    my->setProperty("userName","linux");
    //������Ե�ֵ
    qDebug()<<"userName:"<<my->property("userName").toString();

    //������Զ������ԣ�������������Ч
    my->setProperty("myValue",10);
    qDebug()<<"myValue:"<<my->property("myValue").toInt();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::userChanged(QString username){
    qDebug()<<"user changed:"<<username;
}
