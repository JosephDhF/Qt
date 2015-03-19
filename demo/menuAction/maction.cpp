#include "maction.h"

#include <QLineEdit>
#include <QSplitter>
#include <QLabel>

mAction::mAction(QObject *parent) :
    QWidgetAction(parent)
{
    lineEdit = new QLineEdit;

    //���б༭���İ��»س����ź������ǵķ����ı��ۺ�������
    connect(
                lineEdit,
                SIGNAL(returnPressed()),
                this,
                SLOT(sendText())
                );
}

// ��ʹ�õ�����Ķ��󲢽�����ӵ�һ��������ʱ���ͻ��Զ����øú���
// ��������
QWidget* mAction::createWidget(QWidget *parent){
    //����ʹ�� inherits()�����жϸ������Ƿ��ǲ˵����߹�����
    // ����ǣ��򴴽��ò������Ӳ��������ҷ����Ӳ���
    // ������ǣ���ֱ�ӷ���0
    if (parent->inherits("QMenu") || parent->inherits("QToolBar")){

        QLabel *label = new QLabel;
        label->setText(tr("�����ı�"));

        // ����������
        QSplitter *splitter = new QSplitter(parent);
        splitter->addWidget(label);
        splitter->addWidget(lineEdit);
        return splitter;
    }
    return 0;
}


void mAction::sendText(){
    emit getText(lineEdit->text());//�����ź�
    lineEdit->clear();//����б༭��
}
