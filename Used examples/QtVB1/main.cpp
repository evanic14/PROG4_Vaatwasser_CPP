#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
   QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
   QApplication a(argc, argv);
   MainWindow w;
   // size of the window is 400 x 200
   w.setFixedSize(400,200);
   w.setWindowTitle("1e Window");
   w.show();
   return a.exec();
}
