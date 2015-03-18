#ifndef MACTION_H
#define MACTION_H

#include <QWidgetAction>

class QLineEdit;//ǰ����������

class mAction : public QWidgetAction
{
    Q_OBJECT
public:
    explicit mAction(QObject *parent = 0);

protected:
    //����������ʵ�� QWidgetAction ����麯��
    QWidget* createWidget(QWidget *parent);

signals:
    // �źţ����»س�ʱ�����б༭���е����ݷ����ȥ
    void getText(const QString &string);

public slots:
    // �ۣ�������༭���İ��»س����źŹ���
    void sendText();
private:
    //�����б༭�������ָ��
    QLineEdit* lineEdit;

};

#endif // MACTION_H
