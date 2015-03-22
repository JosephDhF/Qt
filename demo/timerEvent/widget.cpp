#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
#include <QTimer>
#include <QTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

//    id1 = startTimer(1000);// �Ժ���Ϊ��λ
//    id2 = startTimer(2000);
//    id3 = startTimer(3000);

    QTimer *timer = new QTimer(this);
    connect(timer,
            SIGNAL(timeout()),
            this,
            SLOT(timerUpdate()));
    timer->start(1000);//1��

    //�����
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    // ����5����Զ��ر�
    QTimer::singleShot(5000,this,SLOT(close()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == id1){
        qDebug()<<"timer1";
    } else if (event->timerId() == id2){
        qDebug()<<"timer2";
    } else if (event->timerId() == id3){
        qDebug()<<"timer3";
    }
}


void Widget::timerUpdate()
{
    QTime time = QTime::currentTime();
    QString text = time.toString();
    //qDebug()<<"time:"<<text;
    if ((time.second() % 2) == 0)
        text[5] = ' ';//ÿ��1��ͽ� : �޸�Ϊ�ո�
    ui->lcdNumber->display(text);

    int rand = qrand() % 300;
    ui->lcdNumber->move(rand,rand);
}
