#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDialog>
#include "mydialog.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    // ���һ���Ի���
    //QDialog dialog(this); ��ʱ������������ֻ���ڹ��캯����
    //dialog.show(); һ����������Ȼ�͸�Ϊ
    //dialog.exec(); �Ի�������ˣ����������˸����ڵĳ���

//    connect(
//                ui->showChildButton,
//                SIGNAL(clicked()),
//                this,
//                SLOT(showChildDialog())
//            );
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::showChildDialog()
{
    QDialog *dialog = new QDialog(this);
    //dialog->setModal(true);
    dialog->show();
}

void MyWidget::on_showChildButton_clicked(){
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle(QObject::tr("��һ����"));
    dialog->show();
}

void MyWidget::on_relogin_clicked()
{
    // �ȹر������棬��ʵ�������أ��������������˳�
    // ֻ�е�ֻ��һ������ʱ�������������˳�
    close();
    MyDialog dlg;
    // ������¡����������ڡ���ť�����ٴ���ʾ������
    //������Ϊ�����Ѿ�û����ʾ�Ľ����ˣ����Գ����˳�
    if(dlg.exec() == QDialog::Accepted)
        show();
}
