#include "mainwindow.h"
#include "ui_mainwindow.h"

// ���
#include <QTextFrame>

#include <QDebug>

// ���ҹ���
#include <QLineEdit>
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>

// ������ʾ
#include "syntaxhighlighter.h"

// �Զ���ȫ
#include <QStringList>
#include <QCompleter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //���
    // ��ȡ�ĵ�����
    QTextDocument *document = ui->textEdit->document();
    // ��ȡ�����
    QTextFrame *rootFrame = document->rootFrame();
    // ������ܸ�ʽ
    QTextFrameFormat format;
    format.setBorderBrush(Qt::red);//�߽���ɫ
    format.setBorder(3);//�߽���
    rootFrame->setFrameFormat(format);//���ʹ�ø�ʽ

    // ������һ����ܸ�ʽ
    QTextFrameFormat format2;
    format2.setBackground(Qt::lightGray);
    format2.setMargin(0);
    format2.setPadding(5);
    format2.setBorder(2);
    format2.setBorderStyle(QTextFrameFormat::BorderStyle_Dotted);
    //��ȡ���
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.insertFrame(format2);

    QAction *action_textFrame = new QAction(tr("���"),this);
    connect(action_textFrame,
            SIGNAL(triggered()),
            this,
            SLOT(showTextFrame()));
    ui->mainToolBar->addAction(action_textFrame);

    QAction *action_textBlock = new QAction(tr("�ı���"),this);
    connect(action_textBlock,
            SIGNAL(triggered()),
            this,
            SLOT(showTextBlock()));
    ui->mainToolBar->addAction(action_textBlock);

    QAction *action_font = new QAction(tr("����"),this);
    action_font->setCheckable(true);
    connect(action_font,
            SIGNAL(toggled(bool)),
            this,
            SLOT(setTextFont(bool)));
    ui->mainToolBar->addAction(action_font);

    QAction *action_table = new QAction(tr("���"),this);
    connect(action_table,
            SIGNAL(triggered()),
            this,
            SLOT(insertTable()));
    ui->mainToolBar->addAction(action_table);

    QAction *action_list = new QAction(tr("�б�"),this);
    connect(action_list,
            SIGNAL(triggered()),
            this,
            SLOT(insertList()));
    ui->mainToolBar->addAction(action_list);

    QAction *action_image = new QAction(tr("ͼƬ"),this);
    connect(action_image,
            SIGNAL(triggered()),
            this,
            SLOT(insertImage()));
    ui->mainToolBar->addAction(action_image);

    QAction *action_find = new QAction(tr("����"),this);
    connect(action_find,
            SIGNAL(triggered()),
            this,
            SLOT(textFind()));
    ui->mainToolBar->addAction(action_find);

    highlighter = new SyntaxHighlighter(ui->textEdit->document());
    ui->textEdit->append(tr("<h1><font color=red>ʹ��HTML</font></h1>"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showTextFrame()
{
    QTextDocument *document = ui->textEdit->document();
    QTextFrame *frame = document->rootFrame();
    QTextFrame::iterator it;

    for (it = frame->begin(); !(it.atEnd()); ++it){
        QTextFrame *childrenFrame = it.currentFrame();
        QTextBlock childBlock = it.currentBlock();
        if (childrenFrame)
            qDebug()<<"Frame";
        else if (childBlock.isValid())
            qDebug()<<"Block"<<childBlock.text();
    }
}

void MainWindow::showTextBlock(){
    QTextDocument *document = ui->textEdit->document();
    QTextBlock block = document->firstBlock();
    for(int i = 0; i < document->blockCount(); ++i){
        qDebug()<<tr("�ı���%1,�ı��������к�Ϊ��%2������Ϊ��%3������Ϊ")
                   .arg(i).arg(block.firstLineNumber()).arg(block.length())
                << block.text();
        block = block.next();
    }
}

void MainWindow::setTextFont(bool checked){
    if (checked){
        QTextCursor cursor = ui->textEdit->textCursor();//ѡ��
        // �����ı����ʽ
        QTextBlockFormat blockFormat;
        blockFormat.setAlignment(Qt::AlignCenter);
        cursor.insertBlock(blockFormat);

        // �ַ���ʽ
        QTextCharFormat charFormat;
        charFormat.setBackground(Qt::lightGray);
        charFormat.setForeground(Qt::blue);
        charFormat.setFont(QFont(tr("΢���ź�"),12,QFont::Bold,true));
        charFormat.setFontUnderline(true);

        cursor.setCharFormat(charFormat);
        cursor.insertText(tr("��������"));
    }
}

void MainWindow::insertTable(){
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextTableFormat format;
    format.setCellSpacing(2);//��߰�
    format.setCellPadding(10);//�ڱ�
    cursor.insertTable(2,2,format);
}

void MainWindow::insertList(){
    QTextListFormat format;
    format.setStyle(QTextListFormat::ListDecimal);//���ֱ��
    ui->textEdit->textCursor().insertList(format);//����д������
}

void MainWindow::insertImage(){
    QTextImageFormat format;
    format.setName("https://www.baidu.com/img/bdlogo.png");
    ui->textEdit->textCursor().insertImage(format);
}

void MainWindow::textFind(){
    QDialog *dlg = new QDialog(this);//��ģ̬�ĶԻ���
    lineEdit = new QLineEdit(dlg);
    // �������Ұ�ť
    QPushButton *btn = new QPushButton(dlg);
    btn->setText(tr("������һ��"));
    connect(btn,
            SIGNAL(clicked()),
            this,
            SLOT(findNext()));
    //������ֱ���ֶԻ���
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lineEdit);
    layout->addWidget(btn);
    dlg->setLayout(layout);
    dlg->show();
}

void MainWindow::findNext(){
    QString string = lineEdit->text();//��ȡ�����ı�
    //��ʼ���ң�����PHP�� strpos() ����������һ��λ��
    bool isfind = ui->textEdit->find(
                string,
                QTextDocument::FindBackward);//������
    if (isfind){
        qDebug()<<tr("�кţ�%1 �кţ�%2")
                   .arg(ui->textEdit->textCursor().blockNumber())
                   .arg(ui->textEdit->textCursor().columnNumber());
    }
}
