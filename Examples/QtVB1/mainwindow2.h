#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H
#include <QMainWindow>
#include <QPushButton>
namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
   Q_OBJECT

public:
   MainWindow2(QWidget *parent = nullptr);
   ~MainWindow2();
private slots:
   void CloseWindow();
private:
   QPushButton *m_button;
};
#endif // MAINWINDOW2_H
