#include "mywidget.h"
#include "ui_mywidget.h"

#include <QDebug>


MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}

#include <QColorDialog>
void MyWidget::on_color_clicked()
{
    /*
    QColor color = QColorDialog::getColor(
                Qt::red,// ��ʼ��ɫ
                this, // ������
                QObject::tr("��ɫ�Ի���")); //����
    */
    QColorDialog dialog(Qt::red,this);
    dialog.setOption(QColorDialog::ShowAlphaChannel);
    dialog.exec();
    QColor color = dialog.currentColor();
    qDebug() << "color:" << color;
}

#include <QFileDialog>
void MyWidget::on_file_clicked()
{
    QString fileName =
            QFileDialog::getOpenFileName(
                this,
                QObject::tr("ѡ��һ���ļ�"));
    qDebug() << "fileName:" << fileName;
}

#include <QFontDialog>
void MyWidget::on_font_clicked()
{
    bool ok;//���ڱ���Ƿ񵥻��� OK ��ť
    QFont font = QFontDialog::getFont(&ok,this);
    // ��������� OK ��ť����ô�� ������Ի��� ʹ���µ�����
    if (ok)
        ui->font->setFont(font);
    else
        qDebug()<<tr("û��ѡ�����壡");
}

#include <QInputDialog>
void MyWidget::on_input_clicked()
{
    bool ok;
    //��ȡ�ַ���
    QString string = QInputDialog::getText(
                this,
                tr("�ַ����Ի���"),
                tr("�������û�����"),
                QLineEdit::Normal,
                tr("admin"),
                &ok
                );
    if (ok)
        qDebug() << "string:"<<string;

    // ��ȡ����
    int value1 = QInputDialog::getInt(
                this,
                tr("�����Ի���"),
                tr("������-1000 �� 1000 ֮�����ֵ"),
                100,
                -1000,
                1000,10,&ok
                );
    if (ok)
        qDebug()<<"int value:" << value1;

    // ��ȡ������
    double value2 = QInputDialog::getDouble(
                this,
                tr("�������Ի���"),
                tr("������ -1000 �� 1000 ֮�����ֵ"),
                0.00,
                -1000.00,
                1000.00,
                2,&ok
                );
    if (ok)
        qDebug()<<"double:"<<value2;

    //��ȡ��Ŀ
    QStringList items;
    items << tr("��Ŀ1") << tr("��Ŀ2");
    QString item = QInputDialog::getItem(
                this,
                tr("�����Ի���"),
                tr("��ѡ��һ����Ŀ"),
                items,
                0,
                true,&ok
                );
    if (ok)
        qDebug() << "items:" << item;
}

#include <QMessageBox>
void MyWidget::on_message_clicked()
{
    // ����Ի���
    int ret1 = QMessageBox::question(
                this,
                tr("����Ի���"),
                tr("���˽�Qt��"),
                QMessageBox::Yes,
                QMessageBox::No);
    if (ret1 == QMessageBox::Yes)
        qDebug()<<tr("���⣡");
    // ��ʾ�Ի���
    int ret2 = QMessageBox::information(
                this,
                tr("��ʾ�Ի���"),
                tr("����Qt������"),
                QMessageBox::Ok);
    if (ret2 == QMessageBox::Ok)
        qDebug()<<tr("��ʾ");
    // ����Ի���
    int ret3 = QMessageBox::warning(
                this,
                tr("����Ի���"),
                tr("������ǰ������"),
                QMessageBox::Abort);
    if (ret3 == QMessageBox::Abort)
        qDebug()<<tr("����");
    // ����Ի���
    int ret4 = QMessageBox::critical(
                this,
                tr("���ش���Ի���"),
                tr("����һ�����صĴ�������Ҫ�ر������ļ� "),
                QMessageBox::YesAll);
    if (ret4 == QMessageBox::YesAll)
        qDebug()<<tr("����");
    // ���ڶԻ���
    QMessageBox::about(
                this,
                tr("���ڶԻ���"),
                tr("����Qt��������ϰ��"));
}

#include <QProgressDialog>
void MyWidget::on_progress_clicked()
{
    QProgressDialog dialog(
                tr("�ļ����ƽ���"),
                tr("ȡ��"),
                0,50000,this);
    dialog.setWindowTitle(tr("���ȶԻ���"));
    dialog.setWindowModality(Qt::WindowModal);//����Ϊģ̬
    dialog.show();

    for (int i = 0; i< 50000; i++){
        //��ʾ���ƽ���
        dialog.setValue(i);
        QCoreApplication::processEvents();//������涳��
        if(dialog.wasCanceled())
            break;
    }
    dialog.setValue(50000);
    qDebug()<<tr("���ƽ�����");
}

#include <QErrorMessage>
void MyWidget::on_errormsg_clicked()
{
    QErrorMessage *dialog = new QErrorMessage(this);
    dialog->setWindowTitle(tr("������Ϣ�Ի���"));
    dialog->showMessage(tr("�����ǳ�����Ϣ"));
}

// ��ҳ��
QWizardPage * MyWidget::createPage1()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("����"));
    return page;
}
QWizardPage * MyWidget::createPage2()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("�û�ѡ����Ϣ"));
    return page;
}
QWizardPage * MyWidget::createPage3()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("����"));
    return page;
}

void MyWidget::on_guide_clicked()
{
    QWizard wizard(this);
    wizard.setWindowTitle(tr("�򵼶Ի���"));
    wizard.addPage(createPage1());
    wizard.addPage(createPage2());
    wizard.addPage(createPage3());
    wizard.exec();
}
