#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDate>
#include<QTimer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);

    QFont font ( "Microsoft YaHei", 25, 75);//第一个属性是字体（微软雅黑），第二个是大小，第三个是加粗（权重是75）
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label->setFont(font);

    Qt::WindowFlags m_flags = windowFlags();
    setWindowFlags(m_flags | Qt::WindowStaysOnTopHint);

    setWindowTitle("时间窗");
    setWindowIcon(QIcon(":/timg.png"));
    setWindowFlags(windowFlags()&~Qt::WindowMinMaxButtonsHint);


    connect(timer,&QTimer::timeout,[=](){
        QDateTime dateTime(QDateTime::currentDateTime());
        QString qStr = dateTime.toString("hh:mm:ss");
        ui->label->setText(qStr);
    });

    timer->start(10);
    show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
