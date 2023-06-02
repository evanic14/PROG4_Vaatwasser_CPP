#include "mainwindow2.h"

MainWindow2::MainWindow2(QWidget *parent)
   : QMainWindow(parent)
{
   m_button = new QPushButton("Close Window", this);
   m_button->setGeometry(QRect(QPoint(200, 100),
                                QSize(80, 20)));


   // Connect button signal to appropriate slot
   connect(m_button, SIGNAL(clicked()), this, SLOT(CloseWindow()));


}
void MainWindow2::CloseWindow()
{
  this->close();
}

MainWindow2::~MainWindow2()
{
}

