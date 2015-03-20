#include "widget.h"
#include "ui_widget.h"
#include "lineedit.h"
#include <QDebug>

#include <QMouseEvent>
#include <QCursor>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    le = new lineEdit(this);
    le->move(100,100);

    le->installEventFilter(this);

    QCursor cursor;//����������
    cursor.setShape(Qt::OpenHandCursor);//�����״����
    setCursor(cursor);//ʹ�ù��

    // ����������
    //setMouseTracking(true);

    // �������ȡ����
    setFocus();

    keyUp = false;
    keyLeft = false;
    wmove = false;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    // �Ƿ��� ctrl ��
    if (event->modifiers() == Qt::ControlModifier){
        if (event->key() == Qt::Key_M)//�Ƿ���M��
            setWindowState(Qt::WindowMaximized);
    } else if (event->key() == Qt::Key_Up){

        //qDebug()<<"press:"<<event->isAutoRepeat();//�Ƿ��Զ��ظ�
        if (event->isAutoRepeat())
            return;
        keyUp = true;

    } else if(event->key() == Qt::Key_Left){

        if (event->isAutoRepeat())
            return;
        keyLeft = true;

    } else {
        qDebug() << tr("widget �����");
        QWidget::keyPressEvent(event);
    }

}
void Widget::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up){
//        qDebug()<<"release:"<<event->isAutoRepeat();
//        qDebug()<<"up";
        if (event->isAutoRepeat())
            return;
        keyUp = false;
        if (wmove){
            wmove = false;
            return;
        }
        if (keyLeft){
            ui->pushButton->move(30,80);//б��
            wmove = true;
        }else
            ui->pushButton->move(120,80);
    } else if(event->key() == Qt::Key_Left){
        if (event->isAutoRepeat())
            return;
        if (wmove){
            wmove = false;
            return;
        }
        if (keyUp){
            ui->pushButton->move(30,80);
            wmove = true;
        }else{
            ui->pushButton->move(30,120);
        }
    } else if (event->key() == Qt::Key_Down){
        ui->pushButton->move(120,120);
    }
}

// �¼�������
bool Widget::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == le){
        if (event->type() == QEvent::KeyPress)
            qDebug()<<tr("Widget ���¼�������");
    }
    return QWidget::eventFilter(obj,event);
}
// ��갴���¼�
void Widget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        QCursor cursor;
        cursor.setShape(Qt::ClosedHandCursor);
        //��ʱ�ı���״
        QApplication::setOverrideCursor(cursor);
        offset = event->globalPos() - pos();
    } else if (event->button() == Qt::RightButton){
        QPixmap *px = new QPixmap(":/images/66.png");
        QCursor cursor(px->scaledToWidth(20));
        QApplication::setOverrideCursor(cursor);
    }
}
// ����ƶ��¼�
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    // �������ʹ�� buttons ������ƶ�ʱ�޷�����ĸ���������
    if (event->buttons() && Qt::LeftButton){
        QPoint temp;
        // globalPos() ���ָ���λ��
        temp = event->globalPos() - offset;
        move(temp);
    }
}
// �ͷ��¼����ָ���״
void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    QApplication::restoreOverrideCursor();
}
// ˫���¼�
void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        if (windowState() != Qt::WindowFullScreen)
            setWindowState(Qt::WindowFullScreen);
        else
            setWindowState(Qt::WindowNoState);
    }
}
// �����¼�
void Widget::wheelEvent(QWheelEvent *event)
{
    //������Զ��ʹ����
    if (event->delta() > 0)
        ui->textEdit->zoomIn();
    else
        ui->textEdit->zoomOut();
}


