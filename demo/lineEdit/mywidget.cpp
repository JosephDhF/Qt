#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QValidator>
#include <QCompleter>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    // 1.��ʾģʽ
    // 2.��������
    ui->lineEdit2->setInputMask(">AA-90-bb-! aa\#H;*");
    // 3.������֤
    QValidator *validator = new QIntValidator(100,999,this);
    ui->lineEdit3->setValidator(validator);
    // 4.�Զ���ȫ
    QStringList wordList;
    wordList << "Qt" << "Qt Creator" << tr("���");
    QCompleter *completer = new QCompleter(wordList,this);
    completer->setCaseSensitivity(Qt::CaseSensitive);//��Сд������
    ui->lineEdit4->setCompleter(completer);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_lineEdit2_returnPressed()
{
    ui->lineEdit3->setFocus();//��ȡ����
    qDebug()<<ui->lineEdit2->text();//�������
    qDebug()<<ui->lineEdit2->displayText();//�����ʾ����
}
