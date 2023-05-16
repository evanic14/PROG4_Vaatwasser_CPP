#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
   Q_OBJECT
public:
   explicit MainWindow(QWidget *parent = 0);
private slots:
   void handleButton();
   void setLabel();

private:
   QPushButton *m_button1;
   QPushButton *m_button2;
   QLabel *m_label;
};

#endif // MAINWINDOW_H
