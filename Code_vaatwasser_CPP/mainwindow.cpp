#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <string>

#include <QState>
#include <QDateTime>
#include <QDebug>

// Global variables
QString selectedProgram = "none";      /// Char array for displaying the program name
int     selectedTime = 0;              /// Indicates the current selected time
int     powder = 100;                  /// Indicates the level of laundry detergent
int     powderLvl = 0;                 /// Actual laundry detergent level
int     powderErr = 0;                 /// Get set to 1 when powderLvl is 0
int     exitCode = 0;                  /// signal graceful shutdown

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create states
    //QState *S_NO                   = new QState();
    QState *S_INITIALISESUBSYSTEMS = new QState();
    QState *S_WAIT_FOR_PROGRAM     = new QState();
    QState *S_PROCESS_GLASS        = new QState();
    QState *S_PROCESS_CERAMIC      = new QState();
    QState *S_PROCESS_ECO          = new QState();
    QState *S_INSERTED_TIME        = new QState();
    QState *S_START_PROGRAM        = new QState();
    QState *S_RESTART_PROGRAM      = new QState();

    // Set transitions
    //S_NO->addTransition(event(E_START), S_INITIALISESUBSYSTEMS);
    S_INITIALISESUBSYSTEMS->addTransition(ui->minutes60, &QPushButton::clicked, S_WAIT_FOR_PROGRAM);

    // Add states to statemachine
    //statemachine.addState(S_NO);
    statemachine.addState(S_INITIALISESUBSYSTEMS);
    statemachine.addState(S_WAIT_FOR_PROGRAM);
    statemachine.addState(S_PROCESS_GLASS);
    statemachine.addState(S_PROCESS_CERAMIC);
    statemachine.addState(S_PROCESS_ECO);
    statemachine.addState(S_INSERTED_TIME);
    statemachine.addState(S_START_PROGRAM);
    statemachine.addState(S_RESTART_PROGRAM);

    // Set initial state
    //statemachine.setInitialState(S_NO);
    statemachine.setInitialState(S_INITIALISESUBSYSTEMS);

    // Connect states to statefunctions
    connect(S_INITIALISESUBSYSTEMS, &QState::entered, this, &MainWindow::S_InitialiseSubsystems_onEntry);
    connect(S_INITIALISESUBSYSTEMS, &QState::exited,  this, &MainWindow::S_InitialiseSubsystems_onExit);
    connect(S_WAIT_FOR_PROGRAM,     &QState::entered, this, &MainWindow::S_WaitForProgram_onEntry);
    connect(S_WAIT_FOR_PROGRAM,     &QState::exited,  this, &MainWindow::S_WaitForProgram_onExit);
    connect(S_PROCESS_GLASS,        &QState::entered, this, &MainWindow::S_Process_Glass_onEntry);
    connect(S_PROCESS_GLASS,        &QState::exited,  this, &MainWindow::S_Process_Glass_onExit);
    connect(S_PROCESS_CERAMIC,      &QState::entered, this, &MainWindow::S_Process_Ceramic_onEntry);
    connect(S_PROCESS_CERAMIC,      &QState::exited,  this, &MainWindow::S_Process_Ceramic_onExit);
    connect(S_PROCESS_ECO,          &QState::entered, this, &MainWindow::S_Process_Eco_onEntry);
    connect(S_PROCESS_ECO,          &QState::exited,  this, &MainWindow::S_Process_Eco_onExit);
    connect(S_INSERTED_TIME,        &QState::entered, this, &MainWindow::S_InsertedTime_onEntry);
    connect(S_INSERTED_TIME,        &QState::exited,  this, &MainWindow::S_InsertedTime_onExit);
    connect(S_START_PROGRAM,        &QState::entered, this, &MainWindow::S_StartProgram_onEntry);
    connect(S_START_PROGRAM,        &QState::exited,  this, &MainWindow::S_StartProgram_onExit);
    connect(S_RESTART_PROGRAM,      &QState::entered, this, &MainWindow::S_RestartProgram_onEntry);
    connect(S_RESTART_PROGRAM,      &QState::exited,  this, &MainWindow::S_RestartProgram_onExit);

    // Start statemachine
    statemachine.start();

    qDebug() << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ") + "        MainWindow started";
    qDebug() << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ") + "        Statemachine started";

    /*while(event != E_CONTINUE_ERROR) /// While E_CONTINUE_ERROR is NOT triggert display debug
    {
        if(!FSM_NoEvents())
        {
            // Get the event and handle it
            previousEvent = event;
            previousState = state;
            event = FSM_GetEvent();
            state = FSM_EventHandler(state, event);
            DCSdebugSystemInfo("Transition: %s --> %s --> %s", stateEnumToText[previousState], eventEnumToText[event], stateEnumToText[state]);   /// Debug info
        }
    }
    S_ShutdownSystem(exitCode);     /// If E_CONTINUE_ERROR is triggert, shutdown program*/
}

// Functions for states
MainWindow::~MainWindow()
{
    qDebug() << "MainWindow closed";
    delete ui;
}

void MainWindow::S_InitialiseSubsystems_onEntry(void)
{
    qDebug() << "Entered S_InitialiseSubsystems_onEntry";
    // Inform the CVM user
    selectedTime = 0;                                      /// Set time to 0
    selectedProgram = "none";                              /// Set program selection to default
    powderLvl = powder;                                    /// Set powder level to 100 (max)
    powderErr = 0;                                         /// Set powder error to 0

    /*DSPshow(1, "Starting dishwasher");                     /// Display "Starting dishwasher"
    DSPshow(3, "Program started");                         /// Update user interface
    DSPshow(4, "Selected time = %d", selectedTime);        /// Inform user about selected time
    DSPshow(5, "Selected program = %s", selectedProgram);  /// Inform user about selected program
    DSPshow(6, "Powder level = %d", powderLvl);            /// Inform user about powder level
    DSPshow(7, "Powder error = %d", powderErr);            /// Infrom user about powder error state

    DSPshow(9, "Press <ENTER> to continue");               /// Show controls on display

    FSM_AddEvent(E_CONTINUE);                              /// Initialisation done, go to next state*/
}

void MainWindow::S_InitialiseSubsystems_onExit(void)
{
    qDebug() << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ") + "        Entered S_InitialiseSubsystems_onExit";

}

void MainWindow::S_WaitForProgram_onEntry(void)
{
    qDebug() << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ") + "        Entered S_WaitForProgram_onEntry";
    /*DSPshow(1, "Dishwasher");

    DSPshow(3, "Enter a program.");
    DSPshow(4, "<1> Glass");
    DSPshow(5, "<2> Ceramic");
    DSPshow(6, "<3> Eco");

    DSPshow(8, "Press <ENTER> to continue");
    DSPshow(9, "Press <C> to cancel>");

    event_t program = setProgram();          /// Get program information from the program subsystem
    FSM_AddEvent(program);                   /// Gets trigger from setProgram function*/
}

void MainWindow::S_WaitForProgram_onExit(void)
{
    qDebug() << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ") + "        Entered S_WaitForProgram_onExit";

}

void MainWindow::S_Process_Glass_onEntry(void)
{
    qDebug() << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ") + "        Entered S_Process_Glass_onEntry";
    /*time_display();                    /// Displays the time selecion menu
    event_t time = setTime();          /// Call setTime function
    FSM_AddEvent(time);                /// Gets trigger from setTime function*/
}

void MainWindow::S_Process_Glass_onExit(void)
{
    qDebug() << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ") + "        Entered S_Process_Glass_onExit";

}

void MainWindow::S_Process_Ceramic_onEntry(void)
{
    qDebug() << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ") + "        Entered S_Process_Ceramic_onEntry";
    /*time_display();                    /// Displays the time selecion menu
    event_t time = setTime();          /// Call setTime function
    FSM_AddEvent(time);                /// Gets trigger from setTime function*/
}

void MainWindow::S_Process_Ceramic_onExit(void)
{
    qDebug() << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ") + "        Entered S_Process_Ceramic_onExit";

}

void MainWindow::S_Process_Eco_onEntry(void)
{
    qDebug() << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ") + "        Entered S_Process_Eco_onEntry";
    /*time_display();                    /// Displays the time selecion menu
    event_t time = setTime();          /// Call setTime function
    FSM_AddEvent(time);                /// Gets trigger from setTime function*/
}

void MainWindow::S_Process_Eco_onExit(void)
{
    qDebug() << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ") + "        Entered S_Process_Eco_onExit";

}

void MainWindow::S_InsertedTime_onEntry(void)
{
    qDebug() << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ") + "        Entered S_InsertedTime_onEntry";
    //FSM_AddEvent(E_START_PROG); /// Starts the program
}

void MainWindow::S_InsertedTime_onExit(void)
{
    qDebug() << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ") + "        Entered S_InsertedTime_onExit";

}

void MainWindow::S_StartProgram_onEntry(void)
{
    qDebug() << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ") + "        Entered S_StartProgram_onEntry";
    /*DSPshow(1, "Selected program: %s", selectedProgram);
    DSPshow(2, "Selected time: %d", selectedTime);
    DSPshow(4, "Program has started...");

    DSPshow(8, "Press <ENTER> to start program");

    if (powderLvl > 10) /// If powder level is more than 0, return to S_Wait_For_Program
    {
        powderLvl = powderLvl - 10;
        DSPshow(5, "Powder level %d", powderLvl);
        FSM_AddEvent(E_RESTART_PROGRAM);
    }
    else
    {
        powderErr = 1;  /// If powder level is 0, trigger the powderErr error. This will exit the program
        DSPshow(5, "Powder level %d", powderLvl);
        if (powderErr == 1)
        {
            DSPshow(6, "Powder error");
        }
        FSM_AddEvent(E_EMPTY);
        S_ShutdownSystem(1);
    }*/
}

void MainWindow::S_StartProgram_onExit(void)
{
    qDebug() << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ") + "        Entered S_StartProgram_onExit";

}

void MainWindow::S_RestartProgram_onEntry(void)
{
    qDebug() << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ") + "        Entered S_RestartProgram_onEntry";
    /*DSPshow(1, "Restarting");
    selectedProgram =  "none";
    selectedTime = 0;
    FSM_AddEvent(E_RETURN);*/
}

void MainWindow::S_RestartProgram_onExit(void)
{
    qDebug() << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ") + "        Entered S_RestartProgram_onExit";

}

/*void S_ShutdownSystem(int status)
{
    if (status !=0)
    {
        DCSshowSystemError("System shutting down error code %d, state = %", status, stateEnumToText[state]);
    }
    else
    {
        DCSsimulationSystemInfo("System shutting down", status);
    }
    exit(status);
}

/// Subsystems (HAL -- simulations)
event_t setProgram(void)         /// program selector
{
    char kb;
    event_t program = E_RESTART_PROGRAM;

    kb = DCSsimulationSystemInputChar("Enter selection here: ", "123C");
    switch (kb)
    {
    case '1':
        program = E_GLASS;
        selectedProgram = "GLASS";
        break;
    case '2':
        program = E_CERAM;
        selectedProgram = "CERAMIC";
        break;
    case '3':
        program = E_ECO;
        selectedProgram = "ECO";
        break;
    case 'C':
        program = E_RESTART_PROGRAM;
        selectedProgram = "none";
        break;
    default:
        DSPshow(1, "This character is not known");
        selectedProgram = "none";
    }
    return program;
    DSPshowDelete(1, "");
}

event_t setTime(void)            /// time selector
{
    char kb;
    event_t time = E_RESTART_PROGRAM;

    kb = DCSsimulationSystemInputChar("Enter selection here: ", "123456C");
    switch (kb)
    {
    case '1':
        time = E_60;
        selectedTime = selectedTime + 60;
        break;
    case '2':
        time = E_10;
        selectedTime = selectedTime + 10;
        break;
    case '3':
        time = E_5;
        selectedTime = selectedTime + 5;
        break;
    case '4':
        time = E_ADD_TIME;
        selectedTime = selectedTime + 60;
        break;
    case '5':
        time = E_ADD_TIME;
        selectedTime = selectedTime + 10;
        break;
    case '6':
        time = E_ADD_TIME;
        selectedTime = selectedTime + 5;
        break;
    case 'C':
        time = E_RESTART_PROGRAM;
        selectedTime = 0;
        break;
    default:

        DSPshow(1, "This character is not known");
        selectedTime = 0;
    }
    return time;
    DSPshowDelete(1, "");
}*/

/// Helper functions
/// Displays the menu text for the time selection display
void time_display(void)
{
    /*DSPshow(1, "Selected program: %s", selectedProgram);

    DSPshow(3, "Enter desired time:     Current selected time is: %d", selectedTime );
    DSPshow(4, "<1> Add 60 minutes.     <4> Add 60 minutes + more.");
    DSPshow(5, "<2> Add 10 minutes.     <5> Add 10 minutes + more.");
    DSPshow(6, "<3> Add 5 minutes.      <6> Add 5  minutes + more.");

    DSPshow(8, "Press <ENTER> to start program");
    DSPshow(9, "Press <C> to cancel");*/
}
