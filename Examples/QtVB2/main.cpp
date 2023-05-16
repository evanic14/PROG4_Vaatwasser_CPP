#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
   QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
   QApplication a(argc, argv);
   MainWindow w;
   // size of the window is 300 x 300
   w.setFixedSize(300,300);
   w.setWindowTitle("Spongebob");
   w.show();
   return a.exec();
}
