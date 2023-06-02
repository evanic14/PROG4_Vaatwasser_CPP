#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mainwindow2.h"
#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
   Q_OBJECT
public:
   explicit MainWindow(QWidget *parent = 0);
   ~MainWindow();
private slots:
   void CloseWindow();
   void NewWindow();

private:
   QPushButton *m_button1;
   QPushButton *m_button2;
   MainWindow2 *myNewWindow;
 };

#endif // MAINWINDOW_H
