///.h///

#pragma once

#include <QTimer>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *m_pTimer;

//声明槽函数
public slots:
    //响应btn1
    void OnBtn1();

    void OnSetTextStyle();

    void OnSetWindowTitle();

    //相应自定义信号
    void OnSignalMsg();

    //相应btn2 clicked
    void OnBtn2Signal();

    //相应自定义信号
    void OnCustomSignal(int x,int y);


//自定义信号
signals:
    void OnSignalMsg1();

    void OnSignalMsg2();

    void OnSignalMsg3();

    void  signalMsg(int x,int y);


};





///.cpp///

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //一个信号关联多个槽函数 start//
    connect(ui->pbtn1,SIGNAL(clicked()),this,SLOT(OnBtn1()));
    connect(ui->pbtn1,SIGNAL(clicked()),this,SLOT(OnSetTextStyle()));
    connect(ui->pbtn1,SIGNAL(clicked()),this,SLOT(OnSetWindowTitle()));
    //一个信号关联多个槽函数 end

    ///多个信号关联一个槽函数  start//
    connect(this,SIGNAL(OnSignalMsg1()),this,SLOT(OnSignalMsg()()));
    connect(this,SIGNAL(OnSignalMsg2()),this,SLOT(OnSignalMsg()()));
    connect(this,SIGNAL(OnSignalMsg3()),this,SLOT(OnSignalMsg()()));
    ///多个信号关联一个槽函数  end//


    ///一个信号关联多个信号 start//
    ///一个信号关联一个信号start//
    connect(this,SIGNAL(OnSignalMsg3()),ui->pbtn2,SIGNAL(clicked()));
    connect(ui->pbtn2,SIGNAL(clicked()),this,SLOT(OnBtn2Signal()));
    ///一个信号关联一个信号 end//

    connect(this,SIGNAL(OnSignalMsg3()),ui->pbtn2,SIGNAL(pressed()));

    connect(ui->pbtn2, &QPushButton::clicked, this,&MainWindow::OnBtn2Signal);
    ///一个信号关联多个信号 end//


    //带参信号槽
    connect(this,SIGNAL(signalMsg(int,int)),this,SLOT(OnCustomSignal(int,int)));

    //信号槽lambda写法
    m_pTimer = new QTimer(this);

    connect(m_pTimer,&QTimer::timeout,[=]()
    {
        ui->lineEdit_3->setText(QString("你好,中国"));
        ui->lineEdit_4->setText(QString("你好,中国"));
        qDebug()<<"1111"<<endl;
        m_pTimer->stop();
    });
    m_pTimer->start(1000);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnBtn1()
{
    ui->lineEdit1->setText(QString("你好世界"));
    qDebug()<<"OnBtn1"<<endl;
    emit signalMsg(2,3);

}

void MainWindow::OnSetTextStyle()
{
    ui->lineEdit1->setStyleSheet("QLineEdit{background:yellow}");
    qDebug()<<"OnSetTextStyle"<<endl;

}

void MainWindow::OnSetWindowTitle()
{
    this->setWindowTitle(QString("测试窗口"));
    qDebug() << "OnSetWindowTitile" << endl;
    emit OnSignalMsg1();
    emit OnSignalMsg1();
    emit OnSignalMsg1();
}


void MainWindow::OnSignalMsg()
{
    qDebug() << sender()->objectName() << endl;
}


void MainWindow::OnBtn2Signal()
{
    ui->lineEdit_2->setText(QString::fromLocal8Bit("你好,中国"));
   qDebug() << "OnBtn2Signal"<< endl;
}

void MainWindow::OnCustomSignal(int x, int y)
{
   qDebug() << "x" << x << ",y" << y << endl;
}

