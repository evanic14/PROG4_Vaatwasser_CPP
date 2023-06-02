#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
   QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

   QApplication app(argc, argv);
   MainWindow mainWindow;
   // size of the window is 500 x 200
   mainWindow.setFixedSize(500,200);
   mainWindow.show();
   return app.exec();
}
