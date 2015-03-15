#include "mywidget.h"
#include "ui_mywidget.h"

// ��̬ͼƬ
#include <QPixmap>

// ��̬ gif ͼƬ
#include <QMovie>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    ui->frame->setFrameShape(QFrame::Box);
    ui->frame->setFrameShadow(QFrame::Sunken);
    ui->frame->setLineWidth(5);
    ui->frame->setMidLineWidth(10);

    //QLabel ͼƬ
    ui->label->setPixmap(QPixmap("E:/Qt/images/logo.png"));

    //��̬ gif
    QMovie *movie = new QMovie("E:/Qt/images/test.gif");
    ui->labelMovie->setMovie(movie);
    movie->start();

    // Һ������Ч�� QLCDNumber

}

MyWidget::~MyWidget()
{
    delete ui;
}
