#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>

class MyClass : public QObject
{
    Q_OBJECT

    //ע��userName����
    Q_PROPERTY(
        QString userName
        READ getUserName
        WRITE setUserName
        NOTIFY userNameChanged
        );
public:
    explicit MyClass(QObject *parent = 0);

    // ʵ�� READ ����
    QString getUserName() const{
        return m_userName;
    }
    // ʵ�� WRITE ����
    void setUserName(QString userName){
        m_userName = userName;
        // �������޸�ʱ�����ź�
        emit userNameChanged(userName);
    }

signals:
    //���� NOTIFY֪ͨ��Ϣ
    void userNameChanged(QString);

public slots:

private:
    QString m_userName;// ˽�б��������userName

};

#endif // MYCLASS_H
