#include "mainwindow.h"

#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent)
{
   // Create the button, make "this" the parent
   m_button = new QPushButton(this);
   m_button->setGeometry(QRect(QPoint(100, 100),
   QSize(100, 100)));
   m_button->setIcon(QIcon(":/Images/sb.png"));
   //set size of the Icon
   m_button->setIconSize(QSize(200,200));


   // Connect button signal to appropriate slot
   connect(m_button, SIGNAL(clicked()), this, SLOT(handleButton()));
}

void MainWindow::handleButton()
{
   static bool state=true;

   if (state) {
       m_button->setIcon(QIcon(":/Images/pt.png"));
       state = !state;
   }
   else {
       m_button->setIcon(QIcon(":/Images/sb.png"));
       state = !state;
   }
}

