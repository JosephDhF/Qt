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

    qDebug()<<tr("qCopy()�㷨��");

    QVector<QString> vect(3);

    // �� list �����е���Ŀ���Ƶ� vect��

    qCopy(list.begin(),list.end(),vect.begin());
    qDebug()<<vect;

    qDebug()<<endl<<tr("qEaual()�㷨");
    // �� list �Ŀ�ʼ��������������Ŀ��vect�Ŀ�ʼ�������ĵ���������Ŀ
    // ���бȽϣ�ȫ����ͬ�򷵻� true

    bool ret1 = qEqual(list.begin(),list.end(),vect.begin());
    qDebug()<<"equal:"<<ret1;

    qDebug()<<endl<<tr("qFind()�㷨");
    //���ص�һ����Ӧ��ֵ�ĵ����������û���ҵ����򷵻� end()
    QList<QString>::iterator i = qFind(list.begin(),list.end(),"two");
    qDebug()<< *i;

    qDebug()<<endl<<tr("qFill()�㷨");
    qFill(list.begin(),list.end(),"eleven");
    qDebug()<<list;

    QList<int> list1;
    list1 << 3 << 3 << 6 << 6 << 6 << 8;

    qDebug()<<endl<<tr("qCount()�㷨");
    int countOf6 = 0;
    qCount(list1.begin(),list1.empty(),6,countOf6);
    qDebug()<<"countOf6:" << countOf6;

    return a.exec();
}
