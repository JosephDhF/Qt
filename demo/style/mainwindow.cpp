#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWindowsXPStyle>
#include <QDebug>
#include <QStyleFactory>

//��ɫ��
#include <QPalette>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //��������ʹ�÷��
    ui->progressBar->setStyle(new QWindowsXPStyle);

    //��ӡ��ǰϵͳ��֧�ֵķ��
    qDebug()<<QStyleFactory::keys();

    //��ȡ pushButton �ĵ�ɫ��
    QPalette palette1 = ui->pushButton->palette();
    //���ð�ť�ı���ɫΪ��ɫ
    palette1.setColor(QPalette::ButtonText,Qt::red);
    //���ð�ť����ɫΪ��ɫ
    palette1.setColor(QPalette::Button,Qt::green);
    //pushButtonʹ���޸ĺ�ĵ�ɫ��
    ui->pushButton->setPalette(palette1);

    //���� lineEdit ������
    ui->lineEdit->setDisabled(true);
    QPalette palette2 = ui->lineEdit->palette();
    //�����б༭��������ʱ�ı�����ɫΪ��ɫ
    palette2.setColor(QPalette::Disabled,QPalette::Base,Qt::blue);
    ui->lineEdit->setPalette(palette2);
    qDebug()<<Qt::red;
}

MainWindow::~MainWindow()
{
    delete ui;
}
