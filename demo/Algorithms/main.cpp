#include <QtCore/QCoreApplication>

#include <QTextCodec>
#include <QVector>
#include <QStringList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    QStringList list;
    list << "one" << "two" << "three";

    qDebug()<<QObject::tr("qCopy()�㷨��");

    QVector<QString> vect(3);

    // �� list �����е���Ŀ���Ƶ� vect��

    qCopy(list.begin(),list.end(),vect.begin());
    qDebug()<<vect;

    qDebug()<<endl<<QObject::tr("qEaual()�㷨");
    // �� list �Ŀ�ʼ��������������Ŀ��vect�Ŀ�ʼ�������ĵ���������Ŀ
    // ���бȽϣ�ȫ����ͬ�򷵻� true

    bool ret1 = qEqual(list.begin(),list.end(),vect.begin());
    qDebug()<<"equal:"<<ret1;

    qDebug()<<endl<<QObject::tr("qFind()�㷨");
    //���ص�һ����Ӧ��ֵ�ĵ����������û���ҵ����򷵻� end()
    QList<QString>::iterator i = qFind(list.begin(),list.end(),"two");
    qDebug()<< *i;

    qDebug()<<endl<<QObject::tr("qFill()�㷨");
    qFill(list.begin(),list.end(),"eleven");
    qDebug()<<list;

    QList<int> list1;
    list1 << 3 << 3 << 6 << 6 << 6 << 8;

    qDebug()<<endl<<QObject::tr("qCount()�㷨");
    int countOf6 = 0;
    qCount(list1.begin(),list1.end(),6,countOf6);
    qDebug()<<"countOf6:" << countOf6;

    qDebug()<<endl<<QObject::tr("qLowerBound()�㷨");
    // ���ص�һ������5��λ�ã����û��5���򷵻�5Ӧ���ڵ�λ��
    // list1 �����ҵķ�Χ�е���Ŀ����������
    QList<int>::iterator j = qLowerBound(list1.begin(),list1.end(),5);
    list1.insert(j,5);
    qDebug()<<list1;

    QList<int> list2;
    list2 << 33 << 12 << 68 << 6 << 12;
    qDebug()<<endl<<QObject::tr("qSort()�㷨");
    qSort(list2.begin(),list2.end());
    qDebug()<<list2;

    qDebug()<<endl<<QObject::tr("qSwap()�㷨");
    double pi = 3.14;
    double e = 2.71;
    qSwap(pi,e);
    qDebug()<<"pi:"<<pi<<";e:"<<e;


    return a.exec();
}
