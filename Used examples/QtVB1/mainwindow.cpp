#include "mainwindow.h"
#include "mainwindow2.h"
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent)
{

   // Create the button, make "this" the parent
   m_button1 = new QPushButton("New Window", this);
   // set size and location of the button
   m_button1->setGeometry(QRect(QPoint(100, 100),
                                QSize(80, 20)));

   m_button2 = new QPushButton("Close Window", this);
   m_button2->setGeometry(QRect(QPoint(200, 100),
                                QSize(80, 20)));


   // Connect button signal to appropriate slot
   connect(m_button1, SIGNAL(clicked()), this, SLOT(NewWindow()));
   connect(m_button2, SIGNAL(clicked()), this, SLOT(CloseWindow()));
}



void MainWindow::NewWindow()
{
   static int x=0,y=0;
   static int wc=2;
   QString Text;

   myNewWindow = new MainWindow2();
   myNewWindow->setFixedSize(400,200);
   myNewWindow->move(x,y); x=x+10; y=y+10;
   Text.sprintf("%de window",wc); wc++;
   myNewWindow->setWindowTitle(Text);
   myNewWindow->show();
}

void MainWindow::CloseWindow()
{
  this->close();
}

MainWindow::~MainWindow()
{
}

