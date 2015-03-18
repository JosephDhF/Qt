#include "mywidget.h"
#include "ui_mywidget.h"

//�������ֹ�����
#include <QHBoxLayout>
//դ�ֲ��ֹ�����
#include <QGridLayout>

myWidget::myWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWidget)
{
    ui->setupUi(this);
/*
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(ui->fontComboBox);
    layout->addWidget(ui->textEdit);
    layout->setSpacing(50);//�������
    layout->setContentsMargins(0,0,50,100);//���ϣ��ң���
    setLayout(layout);
*/
/*
    QGridLayout *layout = new QGridLayout;
    //��Ӳ������ӵ�0��0�п�ʼ��ռ��1��2��
    layout->addWidget(ui->fontComboBox,
                      0,0,1,2);
    //��0��2�п�ʼ��ռ��1��1��
    layout->addWidget(ui->pushButton,
                      0,2,1,1);
    //��1��0�п�ʼ��ռ��1��3��
    layout->addWidget(ui->textEdit,
                      1,0,1,3);
    setLayout(layout);
*/

}

myWidget::~myWidget()
{
    delete ui;
}
// ���ش��ڰ�ť
void myWidget::on_pushButton_toggled(bool checked)
{
    ui->textEdit->setVisible(checked);
    if (checked)
        ui->pushButton->setText(tr("���ؿ���չ����"));
    else
        ui->pushButton->setText(tr("��ʾ����չ����"));
}
