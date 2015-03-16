#include "mywidget.h"
#include "ui_mywidget.h"

myWidget::myWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWidget)
{
    ui->setupUi(this);

    // ����ʱ��Ϊ����ϵͳʱ��
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    // ����ʱ�����ʾ��ʽ
    ui->dateTimeEdit->setDisplayFormat(
                tr("yyyy��MM��dd�� ddd HHʱmm��ss��")
                // ddd ��ʾ����
                );
}

myWidget::~myWidget()
{
    delete ui;
}
