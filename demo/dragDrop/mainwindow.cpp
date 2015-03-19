#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDragEnterEvent>
#include <QUrl>
#include <QFile>
#include <QTextStream>

#include <QLabel>
#include <QMouseEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ���ô��ڵĲ������϶�
    setAcceptDrops(true);
    QLabel *label = new QLabel(this);
    QPixmap pix("E:/Qt/images/66.png");
    label->setPixmap(pix);
    label->resize(pix.size());
    label->move(100,100);
    // �����ڹر�ʱ����ͼƬ
    label->setAttribute(Qt::WA_DeleteOnClose);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    //�������Ƿ����Url
    if (event->mimeData()->hasUrls())
        event->acceptProposedAction();//���ն���
    else if(event->mimeData()->hasFormat("myimage/png")){
        // �����ƶ�����
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }else
        event->ignore();//�����¼�
}
// �����¼�
void MainWindow::dropEvent(QDropEvent *event)
{
    //��ȡ MIME ����
    const QMimeData *mimeData = event->mimeData();
    if (mimeData->hasUrls()){
        QList<QUrl> urlList = mimeData->urls();//��ȡURL�б�
        //�����е�һ��URL��ʾΪ�����ļ�·��
        QString fileName = urlList.at(0).toLocalFile();
        if (!fileName.isEmpty()){
            QFile file(fileName);
            // ��ֻ����ʽ��
            if (!file.open(QIODevice::ReadOnly))
                return;
            // �����ı�������
            QTextStream in(&file);
            ui->textEdit->setText(in.readAll());
        }
    } else if (mimeData->hasFormat("myimage/png")){
        QByteArray itemData = mimeData->data("myimage/png");
        QDataStream dataStream(&itemData,QIODevice::ReadOnly);
        QPixmap pixmap;
        QPoint offset;
        //ʹ�����������ֽ������е����ݶ��뵽 Qpixmap �� offset
        dataStream >> pixmap >> offset;
        // �½���ǩ��Ϊ�����ͼƬ��������ͼƬ��С���ñ�ǩ�Ĵ�С
        QLabel *newLabel = new QLabel(this);
        newLabel->setPixmap(pixmap);
        newLabel->resize(pixmap.size());
        // ��ͼƬ�ƶ������µ�λ��
        newLabel->move(event->pos()-offset);
        newLabel->show();
        newLabel->setAttribute(Qt::WA_DeleteOnClose);
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}

// ��갴���¼�
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //1.��ȡͼƬ
    // �����ָ������λ�õĲ���ǿ��ת��Ϊ QLable ����
    QLabel *child = static_cast<QLabel *>(childAt(event->pos()));
    if (!child->inherits("QLabel"))
        return;
    //��ȡͼƬ
    QPixmap pixmap = *child->pixmap();

    //2.������MIME����
    QByteArray itemData;
    QDataStream dataStream(&itemData,QIODevice::WriteOnly);
    // ��ͼƬ��Ϣ��λ����Ϣ���뵽�ֽ�������
    dataStream << pixmap << QPoint(event->pos() - child->pos());

    //3.�����ݷ��뵽 QMimeData ��
    QMimeData *mimeData = new QMimeData;
    mimeData->setData("myimage/png",itemData);

    //4.��QMimeData ���ݷ��� QDrap ��
    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);//���ƶ���������ʾͼƬ��������һ��С����
    drag->setHotSpot(event->pos() - child->pos());//�ƶ���������λ��

    //5.��ԭͼƬ�����Ӱ
    QPixmap tempPixmap = pixmap;
    QPainter painter;
    painter.begin(&tempPixmap);
    //��ͼƬ����Ӿ��������һ��͸���ĵ���ɫ������Ӱ
    painter.fillRect(pixmap.rect(),QColor(127,127,127,127));
    painter.end();
    child->setPixmap(tempPixmap);

    //6.ִ���ϷŲ���
    //�����϶��������ƶ��͸��ƣ�Ĭ���Ǹ���
    if (drag->exec(Qt::CopyAction | Qt::MoveAction,
                   Qt::CopyAction)== Qt::MoveAction)
        child->close();
    else{
        child->show();
        child->setPixmap(pixmap);
    }
}

void MainWindow::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("myimage/png")){
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }else{
        event->ignore();
    }
}


