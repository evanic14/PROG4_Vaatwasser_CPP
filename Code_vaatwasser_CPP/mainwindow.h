#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/// Standard CPP includes
//#include <string>
//#include <iostream>
//#include <fstream>
#include <fstream>
#include <iostream>
#include <string>

/// QT CPP includes
#include <QState>
#include <QDateTime>
#include <QDebug>
#include <QCoreApplication>
#include <QThread>
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

    /// Global function prototypes, State related
    void S_InitialiseSubsystems_onEntry(void);
    void S_InitialiseSubsystems_onExit (void);
    void S_WaitForProgram_onEntry      (void);
    void S_WaitForProgram_onExit       (void);
    void S_SelectProgram_onEntry       (void);
    void S_SelectProgram_onExit        (void);

    void S_Process_Glass_onEntry       (void);
    void S_Process_Glass_onExit        (void);
    void S_Process_Ceramic_onEntry     (void);
    void S_Process_Ceramic_onExit      (void);
    void S_Process_Eco_onEntry         (void);
    void S_Process_Eco_onExit          (void);

    //void S_InsertedTime_onEntry(void); // remove from fsm
    //void S_InsertedTime_onExit(void);

    void S_StartProgram_onEntry        (void);
    void S_StartProgram_onExit         (void);
    void S_RestartProgram_onEntry      (void);
    void S_RestartProgram_onExit       (void);

    /// Exception function, for gracefull shutdown
    void S_ShutdownSystem(int exitCode);

private slots:
    /// Event handlers
    void buttonClicked60();
    void buttonClicked10();
    void buttonClicked5();

private:
    Ui::MainWindow *ui;
    QStateMachine statemachine;

    /// Global variables
    std::string filename{"log.txt"};
    std::fstream s;
    QString selectedProgram = "none";      /// String for displaying the program name
    int     selectedTime    = 0;           /// Indicates the current selected time
    int     powder          = 10;         /// Indicates the level of laundry detergent
    int     powderLvl       = 0;           /// Actual laundry detergent level
    int     exitCode        = 0;           /// Signal for a graceful shutdown
    bool    powderErr       = false;       /// Get set to true when powderLvl is 0
    bool    shutdown        = false;       /// Signal for triggering a system shutdown

    /// Create states
    QState *S_INITIALISESUBSYSTEMS = new QState();
    QState *S_WAIT_FOR_PROGRAM     = new QState();
    QState *S_SELECT_PROGRAM       = new QState(); // add state to fsm
    QState *S_PROCESS_GLASS        = new QState();
    QState *S_PROCESS_CERAMIC      = new QState();
    QState *S_PROCESS_ECO          = new QState();
    QState *S_START_PROGRAM        = new QState();
    QState *S_RESTART_PROGRAM      = new QState();

    /// Helper functions
    void timeDisplay    (void);                                                      /// Function for displaying the time selection menu
    void setDisplay     (QString text, bool setDate);                                /// Function for posting text to the display. QString text = input text, bool setDate = enabeles the date display
    void timeDelay      (int time);                                                  /// Delays the program in milliseconds determined by int time
    void debug          (QString text, QString text2, bool setDate, bool setSave);   /// This function posts text to the debug window.
                                                                                     /// QString text = input text, QString text2 = second input text,
                                                                                     /// bool setDate = enables the date display, bool setSave = saves debug info to a file
};

#endif // MAINWINDOW_H
