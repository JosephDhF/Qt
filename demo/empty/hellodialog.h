#ifndef HELLODIALOG_H
#define HELLODIALOG_H

#include <QDialog>

namespace Ui{ //���������ռ�Ui
    class emptyDialog;
    // ǰ������ emptyDialog �࣬�ӿ�����ٶ�
    // ������Ƶ�ͷ�ļ���������Ŀ�����Զ����ɣ�
}

class HelloDialog : public QDialog
{
    Q_OBJECT // Q_OBJECT �꣬��չ C++ �๦��
    // �����źźͲ۹��ܣ��������ඨ���ʼ��
public:
    explicit HelloDialog(QWidget *parent = 0);
    // ��ʾ���캯����ָ��������
signals:

public slots:

private:
    Ui::emptyDialog *ui;//ָ�����
};

#endif // HELLODIALOG_H
