#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>

namespace Ui {
    class MyDialog;
}

class MyDialog : public QDialog
{
    /*
      ʹ��QWidgt���źŲ۹��ܱ������ Q_OBJECT��
      */
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = 0);
    ~MyDialog();

private:
    Ui::MyDialog *ui;
/*
 ֻ�ж�����źŵ��༰������ſ��Է����ź�
 �ź�ֻ������������Ҫʵ��
 �ź�û�з���ֵ
 */
signals:
    void dlgReturn(int);// �Զ�����ź�
private slots:
    void on_pushButton_clicked();
};

#endif // MYDIALOG_H
