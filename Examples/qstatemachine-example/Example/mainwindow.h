#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStateMachine>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void s1_entered(void);
    void s1_exited(void);
    void s2_entered(void);
    void s2_exited(void);
    void s3_entered(void);
    void s3_exited(void);

private:
    Ui::MainWindow *ui;

    QStateMachine statemachine;
};
#endif // MAINWINDOW_H
