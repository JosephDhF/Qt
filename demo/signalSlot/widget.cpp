#include "widget.h"
#include "ui_widget.h"
#include "mydialog.h"

#include <QPushButton>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    QPushButton *button = new QPushButton(this);
    button->setObjectName("myButton");
    // setupUi�����е����� connectSlotsByNameʵ���Զ�����
    ui->setupUi(this);

    MyDialog *dlg = new MyDialog(this);
    connect(dlg,
            SIGNAL(dlgReturn(int)),
            this,
            SLOT(showValue(int)));
    dlg->show();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::showValue(int value)
{
    ui->label->setText(tr("��ȡ����ֵ�ǣ�%1").arg(value));
}

void Widget::on_myButton_clicked(){
    close();
}
