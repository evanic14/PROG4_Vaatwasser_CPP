#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <string>

#include <QState>
#include <QDateTime>
#include <QDebug>
#include <QCoreApplication>
#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lblPowderLvl->setValue(powder); /// initializes powder display level

    /// Add states to statemachine
    statemachine.addState(S_INITIALISESUBSYSTEMS);
    statemachine.addState(S_WAIT_FOR_PROGRAM);
    statemachine.addState(S_SELECT_PROGRAM); // add to fsm
    statemachine.addState(S_PROCESS_GLASS);
    statemachine.addState(S_PROCESS_CERAMIC);
    statemachine.addState(S_PROCESS_ECO);
    //statemachine.addState(S_INSERTED_TIME); // remove from fsm
    statemachine.addState(S_START_PROGRAM);
    statemachine.addState(S_RESTART_PROGRAM);

    /// Set initial state
    statemachine.setInitialState(S_INITIALISESUBSYSTEMS);

    /// Connect states to statefunctions
    connect(ui->btnMinutes60, SIGNAL(clicked()),this,SLOT(buttonClicked60()));
    connect(ui->btnMinutes10, SIGNAL(clicked()),this,SLOT(buttonClicked10()));
    connect(ui->btnMinutes5,  SIGNAL(clicked()),this,SLOT(buttonClicked5()));

    /// Connect states to ste functions
    connect(S_INITIALISESUBSYSTEMS, &QState::entered, this, &MainWindow::S_InitialiseSubsystems_onEntry);
    connect(S_INITIALISESUBSYSTEMS, &QState::exited,  this, &MainWindow::S_InitialiseSubsystems_onExit);
    connect(S_WAIT_FOR_PROGRAM,     &QState::entered, this, &MainWindow::S_WaitForProgram_onEntry);
    connect(S_WAIT_FOR_PROGRAM,     &QState::exited,  this, &MainWindow::S_WaitForProgram_onExit);
    connect(S_SELECT_PROGRAM,       &QState::entered, this, &MainWindow::S_SelectProgram_onEntry); // add to fsm
    connect(S_SELECT_PROGRAM,       &QState::exited,  this, &MainWindow::S_SelectProgram_onExit);
    connect(S_PROCESS_GLASS,        &QState::entered, this, &MainWindow::S_Process_Glass_onEntry);
    connect(S_PROCESS_GLASS,        &QState::exited,  this, &MainWindow::S_Process_Glass_onExit);
    connect(S_PROCESS_CERAMIC,      &QState::entered, this, &MainWindow::S_Process_Ceramic_onEntry);
    connect(S_PROCESS_CERAMIC,      &QState::exited,  this, &MainWindow::S_Process_Ceramic_onExit);
    connect(S_PROCESS_ECO,          &QState::entered, this, &MainWindow::S_Process_Eco_onEntry);
    connect(S_PROCESS_ECO,          &QState::exited,  this, &MainWindow::S_Process_Eco_onExit);
    //connect(S_INSERTED_TIME,        &QState::entered, this, &MainWindow::S_InsertedTime_onEntry); // remove from fsm
    //connect(S_INSERTED_TIME,        &QState::exited,  this, &MainWindow::S_InsertedTime_onExit);
    connect(S_START_PROGRAM,        &QState::entered, this, &MainWindow::S_StartProgram_onEntry);
    connect(S_START_PROGRAM,        &QState::exited,  this, &MainWindow::S_StartProgram_onExit);
    connect(S_RESTART_PROGRAM,      &QState::entered, this, &MainWindow::S_RestartProgram_onEntry);
    connect(S_RESTART_PROGRAM,      &QState::exited,  this, &MainWindow::S_RestartProgram_onExit);



    /// Set transitions
    S_INITIALISESUBSYSTEMS->addTransition(ui->btnOkProg,           &QPushButton::clicked,  S_WAIT_FOR_PROGRAM);

    S_WAIT_FOR_PROGRAM    ->addTransition(ui->btnOkProg,           &QPushButton::clicked,  S_SELECT_PROGRAM); // add to fsm

    S_SELECT_PROGRAM      ->addTransition(ui->btnStateSwGlass,     &QPushButton::clicked , S_PROCESS_GLASS);
    S_SELECT_PROGRAM      ->addTransition(ui->btnStateSwEco,       &QPushButton::clicked,  S_PROCESS_ECO);
    S_SELECT_PROGRAM      ->addTransition(ui->btnStateSwCeramic,   &QPushButton::clicked,  S_PROCESS_CERAMIC);
    S_SELECT_PROGRAM      ->addTransition(ui->btnReturnProg,       &QPushButton::clicked,  S_WAIT_FOR_PROGRAM);

    S_PROCESS_GLASS       ->addTransition(ui->btnOkProg,           &QPushButton::clicked,  S_START_PROGRAM);
    S_PROCESS_GLASS       ->addTransition(ui->btnReturnProg,       &QPushButton::clicked,  S_WAIT_FOR_PROGRAM);

    S_PROCESS_ECO         ->addTransition(ui->btnOkProg,           &QPushButton::clicked,  S_START_PROGRAM);
    S_PROCESS_ECO         ->addTransition(ui->btnReturnProg,       &QPushButton::clicked,  S_WAIT_FOR_PROGRAM);

    S_PROCESS_CERAMIC     ->addTransition(ui->btnOkProg,           &QPushButton::clicked,  S_START_PROGRAM);
    S_PROCESS_CERAMIC     ->addTransition(ui->btnReturnProg,       &QPushButton::clicked,  S_WAIT_FOR_PROGRAM);

    S_START_PROGRAM       ->addTransition(ui->btnOkProg,           &QPushButton::clicked,  S_RESTART_PROGRAM);
    S_START_PROGRAM       ->addTransition(ui->btnStateSwGlass,     &QPushButton::clicked,  S_PROCESS_GLASS);
    S_START_PROGRAM       ->addTransition(ui->btnStateSwEco,       &QPushButton::clicked,  S_PROCESS_ECO);
    S_START_PROGRAM       ->addTransition(ui->btnStateSwEco,       &QPushButton::clicked,  S_PROCESS_CERAMIC);

    S_RESTART_PROGRAM     ->addTransition(ui->btnOkProg,           &QPushButton::clicked,  S_WAIT_FOR_PROGRAM);

    /// Start statemachine
    statemachine.start();

    debug("MainWindow started", "", true);
    debug("Statemachine started", "", true);
}

/// Statefunctions
MainWindow::~MainWindow()
{
    debug(" ", "", false);
    debug("MainWindow closed", "", true);
    delete ui;
}

void MainWindow::S_InitialiseSubsystems_onEntry(void)
{
    debug(" ", "", false);
    debug("Entered S_InitialiseSubsystems_onEntry", "", true);

    /// Hiding button groups
    ui->gbSelCtrl->setVisible(false);
    ui->gbHidden->setVisible(false);
    ui->gbProgram->setVisible(false);
    ui->gbTime->setVisible(false);

    /// Style setip for the LCD time display
    auto palette = ui->txtTime->palette();
    palette.setColor(palette.WindowText, Qt::black);
    palette.setColor(palette.Light, Qt::black);
    palette.setColor(palette.Dark, Qt::black);
    ui->txtTime->setPalette(palette);

    selectedTime = 0;                                               /// Set time to 0
    selectedProgram = "none";                                       /// Set program selection to default
    powderLvl = powder;                                             /// Set powder level to 100 (max)
    powderErr = false;                                              /// Set powder error to 0

    ui->txtTime->display(selectedTime);                             /// Push selected time to LCD

    /// Display "Starting dishwasher"
    debug("Starting dishwasher", "", true);
    setDisplay("Starting dishwasher", false);

    /// Display "Program started"
    debug("Program started", "", true);
    setDisplay("Program started", false);

    /// Inform user about selected time
    QString dispTime = "Selected time = " + QString::number(selectedTime);
    debug(dispTime, "", true);
    setDisplay(dispTime, false);

    /// Inform user about selected program
    QString dispProg = "Selected program = " + selectedProgram;
    debug(dispProg, "", true);
    setDisplay(dispProg, false);

    /// Inform user about powder level
    QString dispPwdr = "Powder level = " + QString::number(powderLvl);
    debug(dispPwdr, "", true);
    setDisplay(dispPwdr, false);

    /// Infrom user about powder error state
    QString dispPwdrErr = "Powder error = " + QString::number(powderErr);
    debug(dispPwdrErr, "", true);
    setDisplay(dispPwdrErr, false);

    /// Show instructions on display
    debug("Press <OK> to continue", "", true);
    setDisplay("Press <OK> to continue", false);

    ui->btnOkProg->animateClick();       /// Generate state change by creating a software induced button trigger
}

void MainWindow::S_InitialiseSubsystems_onExit(void)
{
    timeDelay(2000);                    /// Delaying program by 2 seconds

    ui->txtInfo->clear();               /// Clear display
    ui->gbSelCtrl->setVisible(true);    /// Setting ok and return buttons to visible
}

void MainWindow::S_WaitForProgram_onEntry(void)
{
    debug(" ", "", false);
    debug("Entered S_WaitForProgram_onEntry", "", true);

    /// Hiding and showing button groups
    ui->btnReturnProg->setVisible(false);
    ui->btnOkProg->setVisible(true);
    ui->gbProgram->setVisible(true);

    /// Show instructions on display
    debug("Select program and click <OK>", "", true);
    setDisplay("Select program and click <OK>", false);

    selectedTime = 0;                                             /// Set selectedTime to 0
    ui->txtTime->display(selectedTime);                           /// Push selected time to LCD
}

void MainWindow::S_WaitForProgram_onExit(void)
{
    debug("Entered S_WaitForProgram_onExit", "", true);
    ui->txtInfo->clear();                                          /// Clear display
}

void MainWindow::S_SelectProgram_onEntry(void)
{
    debug(" ", "", false);
    debug("Entered S_SelectProgram_onEntry", "", true);

    /// If loop for detecting the selected program in the program selection combobox
    if (ui->cmbProgramSel->currentText() == "Glass")
    {
        selectedProgram = "Glass";                                  /// Set program to glass
        QString dispText = "Selected program: " + selectedProgram;  /// Concatinate text + current
        debug(dispText, "", true);                                  /// Push concatinated text to debug window
        setDisplay(dispText, false);                                /// Push concatinated text to display

        ui->btnStateSwGlass->animateClick();                        /// Generate state change by creating a software induced button trigger

    }
    else if (ui->cmbProgramSel->currentText() == "Eco")
    {
        selectedProgram = "Eco";                                    /// Set program to eco
        QString dispText = "Selected program: " + selectedProgram;  /// Concatinate text + current
        debug(dispText, "", true);                                  /// Push concatinated text to debug window
        setDisplay(dispText, false);                                /// Push concatinated text to display

        ui->btnStateSwEco->animateClick();                          /// Generate state change by creating a software induced button trigger

    }
    else if (ui->cmbProgramSel->currentText() == "Ceramic")
    {
        selectedProgram = "Ceramic";                                /// Set program to ceramic
        QString dispText = "Selected program: " + selectedProgram;  /// Concatinate text + current
        debug(dispText, "", true);                                  /// Push concatinated text to debug window
        setDisplay(dispText, false);                                /// Push concatinated text to display

        ui->btnStateSwCeramic->animateClick();                      /// Generate state change by creating a software induced button trigger
    }
    else
    {
        debug("No program selected", "", true);                     /// If no program is selected push text to debug window
        setDisplay("No program selected", true);                    /// If no program is selected push text to display

        ui->btnReturnProg->animateClick();                          /// Generate state change by creating a software induced button trigger
    }
}

void MainWindow::S_SelectProgram_onExit(void)
{
    debug("Entered S_SelectProgram_onExit", "", true);

    ui->txtInfo->clear();                                            /// Clear display
    ui->btnReturnProg->setVisible(true);                             /// Set visability of return button
    ui->gbProgram->setVisible(false);                                /// Set visability of program groupbox
}

void MainWindow::S_Process_Glass_onEntry(void)
{
    debug(" ", "", false);
    debug("Entered S_Process_Glass_onEntry", "", true);

    ui->btnOkProg->setVisible(false);                               /// Set visability of ok button

    timeDisplay();                                                  /// Displays the time selecion menu
    QString timeSel = QString::number(selectedTime);                /// Convert int to QString
    debug(timeSel, "", true);                                       /// Send selected time to debug window
    if (selectedTime >= 5)                                          /// If the selected time is 5 minutes or higher, set ok button to visible
    {
        ui->btnOkProg->setVisible(true);
    }
    ui->txtTime->display(selectedTime);                             /// Push selected time to LCD
}

void MainWindow::S_Process_Glass_onExit(void)
{
    debug("Entered S_Process_Glass_onExit", "", true);

    ui->txtInfo->clear();                                           /// Clear display
    ui->gbTime->setVisible(false);                                  /// Set visability of time groupbox
    ui->gbSelCtrl->setVisible(false);                               /// /// Set visability of selection control groupbox
}

void MainWindow::S_Process_Ceramic_onEntry(void)
{
    debug(" ", "", false);
    debug("Entered S_Process_Ceramic_onEntry", "", true);

    ui->btnOkProg->setVisible(false);                               /// Set visability of ok button

    timeDisplay();                                                  /// Displays the time selecion menu
    QString timeSel = QString::number(selectedTime);                /// Convert int to QString
    debug(timeSel, "", true);                                       /// Send selected time to debug window
    if (selectedTime >= 5)                                          /// If the selected time is 5 minutes or higher, set ok button to visible
    {
        ui->btnOkProg->setVisible(true);
    }
    ui->txtTime->display(selectedTime);                             /// Push selected time to LCD
}

void MainWindow::S_Process_Ceramic_onExit(void)
{
    debug("Entered S_Process_Ceramic_onExit", "", true);

    ui->txtInfo->clear();                                           /// Clear display
    ui->gbTime->setVisible(false);                                  /// Set visability of time groupbox
    ui->gbSelCtrl->setVisible(false);                               /// /// Set visability of selection control groupbox
}

void MainWindow::S_Process_Eco_onEntry(void)
{
    debug(" ", "", false);
    debug("Entered S_Process_Eco_onEntry", "", true);

    ui->btnOkProg->setVisible(false);                               /// Set visability of ok button

    timeDisplay();                                                  /// Displays the time selecion menu
    QString timeSel = QString::number(selectedTime);                /// Convert int to QString
    debug(timeSel, "", true);                                       /// Send selected time to debug window
    if (selectedTime >= 5)                                          /// If the selected time is 5 minutes or higher, set ok button to visible
    {
        ui->btnOkProg->setVisible(true);
    }
    ui->txtTime->display(selectedTime);                             /// Push selected time to LCD
}

void MainWindow::S_Process_Eco_onExit(void)
{
    debug("Entered S_Process_Eco_onExit", "", true);

    ui->txtInfo->clear();                                           /// Clear display
    ui->gbTime->setVisible(false);                                  /// Set visability of time groupbox
    ui->gbSelCtrl->setVisible(false);                               /// /// Set visability of selection control groupbox
}

void MainWindow::S_StartProgram_onEntry(void)
{
    debug(" ", "", false);
    debug("Entered S_StartProgram_onEntry", "", true);

    QString dispText1 = "Selected program: " + selectedProgram;             /// Concatinate text + selected program
    debug(dispText1, "", true);                                             /// Push concatinated text to debug window

    QString dispText2 = "Selected time: " + QString::number(selectedTime);  /// Concatinate text + selected time
    debug(dispText2, "", true);                                             /// Push concatinated text to debug window


    debug("Program has started", "", true);

    /// If the selected program is equal to <program>, generate state change by creating a software induced button trigger.
    /// If no suitable text is detected, shutdown the program
    if (selectedProgram == "Glass")
    {
        ui->btnStateSwGlass->animateClick();
    }
    else if (selectedProgram == "Eco")
    {
        ui->btnStateSwEco->animateClick();
    }
    else if (selectedProgram == "Ceramic")
    {
        ui->btnStateSwCeramic->animateClick();
    }
    else
    {
        S_ShutdownSystem(2);                                                ///systemshutdown error code: 2
    }

     /// If powder level is more than 0, return to S_Wait_For_Program
     /// If powder level is 0, set powderErr = true
    if (powderLvl > 10)
    {
        powderLvl = powderLvl - 10;
        QString dispText = "Powder level: " + QString::number(powderLvl);   /// Concatinate text + powder level
        debug(dispText, "", true);                                          /// Push concatinated text to debug window

        ui->lblPowderLvl->setValue(powderLvl);                              /// Push powder level to progressbar
        ui->btnOkProg->animateClick();                                      /// Generate state change by creating a software induced button trigger
    }
    else
    {
        powderErr = true;
        QString dispText = "Powder level: " + QString::number(powderLvl);   /// Concatinate text + powder level
        debug(dispText, "", true);                                          /// Push concatinated text to debug window

         /// If powderErr == true, set shutdown = true
        if (powderErr == true)
        {
            debug("Powder error", "", true);                                /// Push text to debug window
            setDisplay("No washing powder left!", false);                   /// Push text to display window
            shutdown = true;
        }
    }
}

void MainWindow::S_StartProgram_onExit(void)
{
    debug("Entered S_StartProgram_onExit", "", true);
    timeDelay(2000);                                                        /// Delaying program by 2 seconds

    ui->gbTime->setVisible(false);                                          /// Set visability of time groupbox
    ui->txtInfo->clear();                                                   /// Clear display

     /// If shutdown = true, shutdown system
    if (shutdown == true)
    {
        S_ShutdownSystem(1);                                                /// Shutdpwnsystem error code: 1
        shutdown = false;                                                   /// Reset shutdown flag
    }
}

void MainWindow::S_RestartProgram_onEntry(void)
{
    debug(" ", "", false);
    debug("Entered S_RestartProgram_onEntry", "", true);

    debug("Program finished. Returning", "", true);                         /// Push text to debug window
    setDisplay("Program finished. Retuning to program selection", false);   /// Push text to display window
    ui->btnOkProg->animateClick();                                          /// Generate state change by creating a software induced button trigger
}

void MainWindow::S_RestartProgram_onExit(void)
{
    debug("Entered S_RestartProgram_onExit", "", true);
    ui->gbSelCtrl->setVisible(true);                                        /// Set visability of selection control groupbox

    timeDelay(selectedTime * 100);                                          /// Delay program by the amount of time the user has selected
    selectedProgram =  "none";                                              /// Reset the selected program
    selectedTime = 0;                                                       /// Reset the selected time

    ui->txtTime->display(selectedTime);                                     /// Push selected time to LCD
    ui->txtInfo->clear();                                                   /// Clear display
}

void MainWindow::S_ShutdownSystem(int status)
{
    QString dispText = "System shuttingdown. Error code: " + QString::number(status);   /// Concatinate text + status
    debug(dispText, "", true);                                                          /// Push text to debug window
    exit(status);                                                                       /// Exit the program with error code = status
}


/// Event handlers
void MainWindow::buttonClicked60()
{
    selectedTime = selectedTime + 60;                                                   /// Add 60 to selected time
    QString dispText = "Button 60 clicked: " + QVariant(selectedTime).toString();       /// Concatinate text + selectedTime
    debug(dispText, "", true);                                                          /// Push text to debug window

    /// if selected time is higher than 5, set ok button to visible
    if (selectedTime >= 5)
    {
        ui->btnOkProg->setVisible(true);
    }
    ui->txtTime->display(selectedTime);                                                 /// Push selected time to LCD
}

void MainWindow::buttonClicked10()
{
    selectedTime = selectedTime + 10;                                                   /// Add 10 to selected time
    QString dispText = "Button 10 clicked: " + QVariant(selectedTime).toString();       /// Concatinate text + selectedTime
    debug(dispText, "", true);                                                          /// Push text to debug window

    /// if selected time is higher than 5, set ok button to visible
    if (selectedTime >= 5)
    {
        ui->btnOkProg->setVisible(true);
    }
    ui->txtTime->display(selectedTime);                                                 /// Push selected time to LCD
}

void MainWindow::buttonClicked5()
{
    selectedTime = selectedTime + 5;                                                    /// Add 5 to selected time
    QString dispText = "Button 5 clicked: " + QVariant(selectedTime).toString();        /// Concatinate text + selectedTime
    debug(dispText, "", true);                                                          /// Push text to debug window

    /// if selected time is higher than 5, set ok button to visible
    if (selectedTime >= 5)
    {
        ui->btnOkProg->setVisible(true);
    }
    ui->txtTime->display(selectedTime);                                                 /// Push selected time to LCD
}

/// Helper functions
/// Displays the menu text for the time selection display
void MainWindow::timeDisplay(void)
{
    QString dispText = "Selected program: " + selectedProgram;                         /// Concatinate text + selectedProgram
    debug(dispText, "", true);                                                         /// Push text to debug window
    setDisplay(dispText, false);                                                       /// Push text to display window

    ui->gbTime->setVisible(true);                                                      /// Set groupbox time to visible

    // Show instructions on display
    debug("Enter desired time", "", true);
    setDisplay("Enter desired time", false);

    debug("Press <OK> to start program", "", true);
    setDisplay("Press <OK> to start program", false);

    debug("Press <Return> to cancel program", "", true);
    setDisplay("Press <Return> to cancel program", false);
}

void MainWindow::setDisplay(QString text, bool setDate)
{
    QString logstring;                                                                /// Create QString called logstring
    /// If setDate = true,
    /// include the date in the display message
    if (setDate == true)
    {
        logstring = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:  " + text);
    }
    else
    {
        logstring = text;
    }
    ui->txtInfo->appendPlainText(logstring);                                          /// Push text to display
}

void MainWindow::timeDelay(int time)
{
    QString dispText = "Waiting for: " + QString::number(time) + "ms";                /// Concatinate text + time + ms
    debug(dispText, "", true);                                                        /// Push text to debug window
    setDisplay("Please wait...", false);                                              /// Push text to display window

    QThread::msleep(time);                                                            /// Stop program for the value that int time has in milliseconds
}

void MainWindow::debug(QString text, QString text2, bool setDate)
{
    /// If setDate = true,
    /// include the date in the display message
    if (setDate == true)
    {
        qDebug() << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss: ") + "        " + text + " " + text2;
    }
    else
    {
        qDebug() << text + " " + text2;
    }
}
