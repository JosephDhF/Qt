#include "mydialog.h"
#include "ui_mydialog.h"
#include <QDebug>

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    qDebug()<<"MyDialog::MyDialog - start";
    ui->setupUi(this);
    qDebug()<<"MyDialog::MyDialog - end";
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::on_toMain_clicked(){
    accept();// ��ʹ�� exec() ����ʾ����ʱ
    //done(2);
    //accept() �᷵�� QDialog::Accepted ֵ
}
