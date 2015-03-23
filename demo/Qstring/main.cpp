#include <QtCore/QCoreApplication>
#include <QTextCodec>
#include <QDebug>
#include <QStringList>

void QstringEdit(){
    qDebug()<<QObject::tr("�����Ǳ༭�ַ�������")<<endl;

    QString str = "Hello";
    qDebug()<<"string size:"<<str.size();
    qDebug()<<"string length"<<str.length();

    str[0] = QChar('h');
    qDebug()<<QObject::tr("��һ���ַ��޸ĺ�")<< str;

    str.append(" Qt");
    str.replace(1,4,"i");
    str.insert(2," my");
    qDebug()<<"str:"<<str;

    str = str + "!!!";
    qDebug()<<QObject::tr("ʹ�üӺ����ӣ�")<<str;

    str="hi\r\n Qt!\n ";
    qDebug()<<QObject::tr("str=")<<str;

    QString str1 = str.trimmed();//��ȥ�ַ������˵Ŀհ�
    qDebug()<<QObject::tr("str1:")<<str1;

    QString str2 = str.simplified();// ȥ�����˼��м����Ŀհ�
    qDebug()<<QObject::tr("str2:")<<str2;

    str = "hi,my,,Qt";
    //���ַ������� �� �ĵط������Ϊ������ַ���
    // QString::SkipEmptyParts ��ʾ�����յ���Ŀ
    QStringList list = str.split(",",QString::SkipEmptyParts);
    qDebug()<<QObject::tr("str��ֺ�Ϊ��")<<list;

    str = list.join(" ");//���
    qDebug()<<QObject::tr("list��ȫ��Ϊ��")<<str;

    qDebug()<<QString().isNull();
    qDebug()<<QString().isEmpty();
    qDebug()<<QString("").isNull();
    qDebug()<<QString("").isEmpty();
}

void QstringQuery(){
    qDebug()<<QObject::tr("���������ַ����н��в�ѯ������");

    QString str="yafeilinux";
    qDebug()<<QObject::tr("�ַ���Ϊ��")<<str;

    // ִ������һ�д���󣬽��Ϊ linux
    qDebug()<<QObject::tr("�����Ҳ�5���ַ������ַ�����")<<str.right(5);
    qDebug()<<QObject::tr("�������5�����д������ַ�����")<<str.left(5);

    //ִ������һ�д���󣬽��Ϊfei
    qDebug()<<QObject::tr("������2���ַ��Ժ�3���ַ������ַ�����")<<str.mid(2,3);
    qDebug()<<QObject::tr("fei��λ�ã�")<<str.indexOf("fei");
    qDebug()<<QObject::tr("str�ĵ�0���ַ�����")<<str.at(0);
    qDebug()<<QObject::tr("str��i�ַ��ĸ�����")<<str.count('i');

    qDebug()<<QObject::tr("str�Ƿ���ya��ʼ��")<<str.startsWith("ya");
    qDebug()<<QObject::tr("�Ƿ���linux��β��")<<str.endsWith("linux");
    qDebug()<<QObject::tr("str�Ƿ����lin�ַ�����")<<str.contains("lin");

    QString temp = "hello";

    if (temp > str)
        qDebug()<<temp;
    else
        qDebug()<<str;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    qDebug()<<QObject::tr("�������ַ�����ת��������")<<endl;

    QString str="100";
    qDebug()<<QObject::tr("�ַ���ת��Ϊ����")<<str.toInt();

    int num = 45;
    qDebug()<<QObject::tr("����ת��Ϊ�ַ�����")<<QString::number(num);

    str = "FF";
    bool ok;

    int hex = str.toInt(&ok,16);
    // ���Ϊ ok: true 255
    qDebug()<<"ok"<<ok<<QObject::tr("ת��Ϊ16���ƣ�")<<hex;


    return a.exec();
}
