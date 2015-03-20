#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class lineEdit;

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    bool eventFilter(QObject *obj, QEvent *event);

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    // ����¼�
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

    void mouseDoubleClickEvent(QMouseEvent *event);

private:
    Ui::Widget *ui;
    lineEdit *le;

    QPoint offset;// �����洢���ָ��λ���봰��λ�õĲ�ֵ

    //�����ť���Զ��ظ������Ų��ţ�
    bool keyUp;//���Ϸ�����ı�־
    bool keyLeft;
    bool wmove;//�Ƿ����һ���ƶ�
};

#endif // WIDGET_H
