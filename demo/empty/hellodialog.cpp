#include "hellodialog.h"
#include "ui_emptydialog.h"

HelloDialog::HelloDialog(QWidget *parent) :
    QDialog(parent)
{
    ui = new Ui::emptyDialog;
    //Ϊ�����������ĶԻ��򴴽�����
    ui->setupUi(this);
}
