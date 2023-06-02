#include "mainwindow.h"

 #include <QCoreApplication>

 MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
 {
    // Create the button, make "this" the parent
    m_button1 = new QPushButton("Button 1", this);
    // set size and location of the button
    m_button1->setGeometry(QRect(QPoint(100, 100),
    QSize(80, 20)));

    m_button2 = new QPushButton("Button 2", this);
    m_button2->setGeometry(QRect(QPoint(200, 100),
    QSize(80, 20)));

    m_label = new QLabel("Label",this);
    m_label->setGeometry(QRect(QPoint(10,10),QSize(50,50)));


    // Connect button signal to appropriate slot
    connect(m_button1, SIGNAL(clicked()), this, SLOT(setLabel()));
    connect(m_button2, SIGNAL(clicked()), this, SLOT(handleButton()));
 }

 void MainWindow::handleButton()
 {
    // change the text
    m_button2->setText("Example");
    // resize button
    m_button2->resize(60,30);
 }

 void MainWindow::setLabel()
 {
    m_label->setText("Test");
 }
