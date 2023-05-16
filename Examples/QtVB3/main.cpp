#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
   QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
   QApplication a(argc, argv);
   MainWindow w;
   w.setFixedSize(900,600);
   w.setWindowTitle("Pictures");
   w.show();
   return a.exec();
}
