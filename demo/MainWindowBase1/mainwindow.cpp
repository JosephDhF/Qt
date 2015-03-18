#include "mainwindow.h"
#include "ui_mainwindow.h"

// ����������������ڲ���
#include <QToolButton>
#include <QSpinBox>

// ״̬����Ϣ
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //��ӱ༭�˵�
    QMenu *editMenu = ui->menuBar->addMenu(tr("�༭(&E)"));
    //Ϊ�˵����Action
    QAction *action_Open = editMenu->addAction(
                QIcon(":/images/images/open.png"),
                tr("���ļ�(&O)")
                );
    //���ÿ�ݼ�
    action_Open->setShortcut(QKeySequence("Ctrl+O"));
    //��Action��ӵ�������
    ui->mainToolBar->addAction(action_Open);

    // QAction �飬�������õ�ѡ
    QActionGroup *group = new QActionGroup(this);
    QAction *action_L = group->addAction(tr("�����(&L)"));
    // �����Ƿ�ѡ��״̬
    action_L->setCheckable(true);
    QAction *action_R = group->addAction(tr("�Ҷ���(&R)"));
    action_R->setCheckable(true);
    QAction *action_C = group->addAction(tr("���ж���(&C)"));
    action_C->setCheckable(true);
    // ��Ӽ����
    editMenu->addSeparator();
    // ��˵�����Ӷ���
    editMenu->addAction(action_L);
    editMenu->addAction(action_C);
    editMenu->addAction(action_R);

    //�ڹ���������������ڲ���
    QToolButton *toolBtn = new QToolButton(this);
    toolBtn->setText(tr("��ɫ"));
    //���õ�����ʽ
    toolBtn->setPopupMode(QToolButton::MenuButtonPopup);
    ui->mainToolBar->addWidget(toolBtn);

    //����һ���˵�
    QMenu *colorMenu = new QMenu(this);
    colorMenu->addAction(tr("��ɫ"));
    colorMenu->addAction(tr("��ɫ"));
    toolBtn->setMenu(colorMenu);

    QSpinBox *spinBox = new QSpinBox(this);
    ui->mainToolBar->addWidget(spinBox);

    //��״̬�������Ϣ
    // ��ʾ��ʱ��Ϣ����ʾ 2000 ���뼴 2����
    ui->statusBar->showMessage(tr("��ӭʹ�ö��ĵ��༭��"),2000);
    // ������ǩ
    QLabel *permanent = new QLabel(this);
    permanent->setFrameStyle(QFrame::Box|QFrame::Sunken);
    permanent->setText("2015-03-18");
    ui->statusBar->addPermanentWidget(permanent);
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include <QTextEdit>
#include <QMdiSubWindow>
void MainWindow::on_action_N_triggered()
{
    // �½��ı��༭������
    QTextEdit *edit = new QTextEdit(this);
    // ʹ��QMdiArea��� addSubWindow()���������Ӵ���
    // ���ı��༭��Ϊ���Ĳ���
    QMdiSubWindow *child = ui->mdiArea->addSubWindow(edit);
    child->setWindowTitle(tr("���ĵ��༭���Ӵ���"));
    child->show();
}

void MainWindow::on_showDock_triggered()
{
    if(ui->dockWidget->isVisible())
        ui->dockWidget->hide();
    else
        ui->dockWidget->show();
}
