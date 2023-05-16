#include "mainwindow.h"

#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent)
{
   // Create the button, make "this" the parent
   m_button = new QPushButton(this);
   m_button->setGeometry(QRect(QPoint(800, 5),QSize(80, 20)));
   m_button->setText("Switch Picture");

   // Create image for picture
   m_label = new QLabel(this);
   m_label->setGeometry(0,0,800,600);
   m_label->setPixmap(QPixmap(":\\Images\\plaatje1.jpg"));
   // Connect button signal to appropriate slot
   connect(m_button, SIGNAL(clicked()), this, SLOT(handleButton()));
}

void MainWindow::handleButton()
{
   static bool state=true;

   if (!state)  {
       m_label->setPixmap(QPixmap(":\\Images\\plaatje1.jpg"));
       state = !state;
   }
   else  {
       m_label->setPixmap(QPixmap(":\\Images\\plaatje2.jpg"));
       state = !state;
   }
}

