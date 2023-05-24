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

    /// Helper functions
    void time_display(void);

    /// Global function prototypes, State related
    void S_InitialiseSubsystems_onEntry(void);
    void S_InitialiseSubsystems_onExit(void);
    void S_WaitForProgram_onEntry(void);
    void S_WaitForProgram_onExit(void);

    void S_Process_Glass_onEntry(void);
    void S_Process_Glass_onExit(void);
    void S_Process_Ceramic_onEntry(void);
    void S_Process_Ceramic_onExit(void);
    void S_Process_Eco_onEntry(void);
    void S_Process_Eco_onExit(void);

    void S_InsertedTime_onEntry(void);
    void S_InsertedTime_onExit(void);

    void S_StartProgram_onEntry(void);
    void S_StartProgram_onExit(void);
    void S_RestartProgram_onEntry(void);
    void S_RestartProgram_onExit(void);

    /// Exception function, for gracefull shutdown
    void S_ShutdownSystem(int exitCode);

private:
    Ui::MainWindow *ui;
    QStateMachine statemachine;
};

#endif // MAINWINDOW_H
