#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDateTime>
#include <QDebug>

//          *                                 +---------+
//          |                                 |         |
//          v                                 v         | button 2
//     +--------+                         +--------+    | clicked
//     |   S1   |                         |   S2   |----+
//     +--------+    button 2 clicked     +--------+
//     |        |------------------------>|        |
//     +--------+                         +--------+
//          ^                                  |
//          | button 1                         | button 3
//          | clicked   +--------+             | clicked
//          |           |   S3   |             |
//          |           +--------+             |
//          +-----------|        |<------------+
//                      +--------+

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QState *s1 = new QState();
    QState *s2 = new QState();
    QState *s3 = new QState();

    s1->addTransition(ui->pb2, &QPushButton::clicked, s2);
    s2->addTransition(ui->pb2, &QPushButton::clicked, s2);
    s2->addTransition(ui->pb3, &QPushButton::clicked, s3);
    s3->addTransition(ui->pb1, &QPushButton::clicked, s1);

    statemachine.addState(s1);
    statemachine.addState(s2);
    statemachine.addState(s3);
    statemachine.setInitialState(s1);

    connect(s1, &QState::entered, this, &MainWindow::s1_entered);
    connect(s1, &QState::exited, this, &MainWindow::s1_exited);
    connect(s2, &QState::entered, this, &MainWindow::s2_entered);
    connect(s2, &QState::exited, this, &MainWindow::s2_exited);
    connect(s3, &QState::entered, this, &MainWindow::s3_entered);
    connect(s3, &QState::exited, this, &MainWindow::s3_exited);

    statemachine.start();

    qDebug() << "MainWindow started";
    qDebug() << "Statemachine started started";
}

MainWindow::~MainWindow()
{
    qDebug() << "MainWindow closed";
    delete ui;
}

void MainWindow::s1_entered(void)
{
    QString logstring;

    logstring = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ");
    logstring += "Entered state S1";
    ui->plainTextEdit->appendPlainText(logstring);

    ui->userInfo->appendPlainText("Click 2 to go to state 2");
}

void MainWindow::s1_exited(void)
{
    QString logstring;

    logstring = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ");
    logstring += "Exited state S1";
    ui->plainTextEdit->appendPlainText(logstring);
}

void MainWindow::s2_entered(void)
{
    QString logstring;

    logstring = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ");
    logstring += "Entered state S2";
    ui->plainTextEdit->appendPlainText(logstring);

    ui->userInfo->appendPlainText("Click 2 to go to state 2 or "
                                  "click 3 to go to state 3");
}

void MainWindow::s2_exited(void)
{
    QString logstring;

    logstring = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ");
    logstring += "Exited state S2";
    ui->plainTextEdit->appendPlainText(logstring);
}

void MainWindow::s3_entered(void)
{
    QString logstring;

    logstring = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ");
    logstring += "Entered state S3";
    ui->plainTextEdit->appendPlainText(logstring);

    ui->userInfo->appendPlainText("Click 1 to go to state 1");
}

void MainWindow::s3_exited(void)
{
    QString logstring;

    logstring = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ");
    logstring += "Exited state S3";
    ui->plainTextEdit->appendPlainText(logstring);
}
