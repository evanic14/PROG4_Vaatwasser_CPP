#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QPainter>

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

private:
   QPushButton *m_button;
   QLabel *m_label;
   QPixmap *m_pixmap;
};

#endif // MAINWINDOW_H
