/// library decleration
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "fsm_functions/fsm.h"
#include "console_functions/keyboard.h"
#include "console_functions/display.h"
#include "console_functions/devConsole.h"

extern char * eventEnumToText[];
extern char * stateEnumToText[];

state_t state;
event_t event;
state_t previousState;
event_t previousEvent;

char selectedProgram[10] = "none";  /// Char array for displaying the program name
int  selectedTime = 0;              /// Indicates the current selected time
int  powder = 100;                  /// Indicates the level of laundry detergent
int  powderLvl = 0;                 /// Actual laundry detergent level
int  powderErr = 0;                 /// Get set to 1 when powderLvl is 0
int  exitCode = 0;                  /// signal graceful shutdown

/// Local function prototypes State related
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

/// Subsystems
event_t setProgram(void);        ///program selector
event_t setTime(void);           ///time selector

/// helper functions
void time_display(void);
void delay_ms(uint32_t d);

/// Main
int statemachine(void)
{
    ///          State                                     onEntry()                       onExit()
    FSM_AddState(S_INITIALISESUBSYSTEMS,&(state_funcs_t){  S_InitialiseSubsystems_onEntry, S_InitialiseSubsystems_onExit });
    FSM_AddState(S_WAIT_FOR_PROGRAM,    &(state_funcs_t){  S_WaitForProgram_onEntry,       S_WaitForProgram_onExit });
    FSM_AddState(S_PROCESS_GLASS,       &(state_funcs_t){  S_Process_Glass_onEntry,        S_Process_Glass_onExit });
    FSM_AddState(S_PROCESS_CERAMIC,     &(state_funcs_t){  S_Process_Ceramic_onEntry,      S_Process_Ceramic_onExit });
    FSM_AddState(S_PROCESS_ECO,         &(state_funcs_t){  S_Process_Eco_onEntry,          S_Process_Eco_onExit });
    FSM_AddState(S_INSERTED_TIME,       &(state_funcs_t){  S_InsertedTime_onEntry,         S_InsertedTime_onExit });
    FSM_AddState(S_START_PROGRAM,       &(state_funcs_t){  S_StartProgram_onEntry,         S_StartProgram_onExit });
    FSM_AddState(S_RESTART_PROGRAM,     &(state_funcs_t){  S_RestartProgram_onEntry,       S_RestartProgram_onExit });

    ///                                From                     Event               To
    FSM_AddTransition(&(transition_t){ S_NO,                    E_START,            S_INITIALISESUBSYSTEMS });
    FSM_AddTransition(&(transition_t){ S_INITIALISESUBSYSTEMS,  E_CONTINUE,         S_WAIT_FOR_PROGRAM });
    FSM_AddTransition(&(transition_t){ S_INITIALISESUBSYSTEMS,  E_CONTINUE,         S_STOP });

    FSM_AddTransition(&(transition_t){ S_WAIT_FOR_PROGRAM,      E_GLASS,            S_PROCESS_GLASS });
    FSM_AddTransition(&(transition_t){ S_WAIT_FOR_PROGRAM,      E_CERAM,            S_PROCESS_CERAMIC });
    FSM_AddTransition(&(transition_t){ S_WAIT_FOR_PROGRAM,      E_ECO,              S_PROCESS_ECO });

    FSM_AddTransition(&(transition_t){ S_PROCESS_GLASS,         E_60,               S_INSERTED_TIME });
    FSM_AddTransition(&(transition_t){ S_PROCESS_GLASS,         E_10,               S_INSERTED_TIME });
    FSM_AddTransition(&(transition_t){ S_PROCESS_GLASS,         E_5,                S_INSERTED_TIME });
    FSM_AddTransition(&(transition_t){ S_PROCESS_GLASS,         E_ADD_TIME,         S_PROCESS_GLASS });

    FSM_AddTransition(&(transition_t){ S_PROCESS_CERAMIC,       E_60,               S_INSERTED_TIME });
    FSM_AddTransition(&(transition_t){ S_PROCESS_CERAMIC,       E_10,               S_INSERTED_TIME });
    FSM_AddTransition(&(transition_t){ S_PROCESS_CERAMIC,       E_5,                S_INSERTED_TIME });
    FSM_AddTransition(&(transition_t){ S_PROCESS_CERAMIC,       E_ADD_TIME,         S_PROCESS_CERAMIC });

    FSM_AddTransition(&(transition_t){ S_PROCESS_ECO,           E_60,               S_INSERTED_TIME });
    FSM_AddTransition(&(transition_t){ S_PROCESS_ECO,           E_10,               S_INSERTED_TIME });
    FSM_AddTransition(&(transition_t){ S_PROCESS_ECO,           E_5,                S_INSERTED_TIME });
    FSM_AddTransition(&(transition_t){ S_PROCESS_ECO,           E_ADD_TIME,         S_PROCESS_ECO });

    FSM_AddTransition(&(transition_t){ S_INSERTED_TIME,         E_START_PROG,       S_START_PROGRAM });
    FSM_AddTransition(&(transition_t){ S_START_PROGRAM,         E_ADD_TIME,         S_INSERTED_TIME });

    FSM_AddTransition(&(transition_t){ S_START_PROGRAM,         E_RESTART_PROGRAM,  S_RESTART_PROGRAM });
    FSM_AddTransition(&(transition_t){ S_WAIT_FOR_PROGRAM,      E_RESTART_PROGRAM,  S_WAIT_FOR_PROGRAM });
    FSM_AddTransition(&(transition_t){ S_PROCESS_GLASS,         E_RESTART_PROGRAM,  S_RESTART_PROGRAM });
    FSM_AddTransition(&(transition_t){ S_PROCESS_CERAMIC,       E_RESTART_PROGRAM,  S_RESTART_PROGRAM });
    FSM_AddTransition(&(transition_t){ S_PROCESS_ECO,           E_RESTART_PROGRAM,  S_RESTART_PROGRAM });

    FSM_AddTransition(&(transition_t){ S_START_PROGRAM,         E_EMPTY,            S_STOP });
    FSM_AddTransition(&(transition_t){ S_START_PROGRAM,         E_CONTINUE_ERROR,   S_RESTART_PROGRAM });

    FSM_AddTransition(&(transition_t){ S_RESTART_PROGRAM,       E_RETURN,           S_WAIT_FOR_PROGRAM });

    /// Should unexpected events in a state be flushed or not?
    FSM_FlushEnexpectedEvents(true);

    /// Set the finite state machine in the S_NO state
    /// and add a E_START event into the event buffer
    state = S_NO;                    /// Begin state
    FSM_AddEvent(E_START);           /// Machine is switched on

    while(event != E_CONTINUE_ERROR) /// While E_CONTINUE_ERROR is NOT triggert display debug
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
    S_ShutdownSystem(exitCode);     /// If E_CONTINUE_ERROR is triggert, shutdown program
}

void S_InitialiseSubsystems_onEntry(void)
{

    // Initalize the debug console
    DSPinitialise();                                      /// Initialise User interface
    DSPshowDisplay();                                     /// And debug console
    DCSinitialise();
    KYBinitialise();

    // Inform the CVM user
    selectedTime = 0;                                      /// Set time to 0
    strcpy(selectedProgram, "none");                       /// Set program selection to default
    powderLvl = powder;                                    /// Set powder level to 100 (max)
    powderErr = 0;                                         /// Set powder error to 0

    DSPshow(1, "Starting dishwasher");                     /// Display "Starting dishwasher"
    DSPshow(3, "Program started");                         /// Update user interface
    DSPshow(4, "Selected time = %d", selectedTime);        /// Inform user about selected time
    DSPshow(5, "Selected program = %s", selectedProgram);  /// Inform user about selected program
    DSPshow(6, "Powder level = %d", powderLvl);            /// Inform user about powder level
    DSPshow(7, "Powder error = %d", powderErr);            /// Infrom user about powder error state

    DSPshow(9, "Press <ENTER> to continue");               /// Show controls on display

    FSM_AddEvent(E_CONTINUE);                              /// Initialisation done, go to next state
}

void S_InitialiseSubsystems_onExit(void)
{
    DSPshowDelete(1, "");
    DCSdebugSystemInfo("Curent state: %s, Current event: %s", stateEnumToText[state], eventEnumToText[event]);   /// Debug info
}

void S_WaitForProgram_onEntry(void)
{
    DSPshow(1, "Dishwasher");

    DSPshow(3, "Enter a program.");
    DSPshow(4, "<1> Glass");
    DSPshow(5, "<2> Ceramic");
    DSPshow(6, "<3> Eco");

    DSPshow(8, "Press <ENTER> to continue");
    DSPshow(9, "Press <C> to cancel>");

    event_t program = setProgram();          /// Get program information from the program subsystem
    FSM_AddEvent(program);                   /// Gets trigger from setProgram function
}

void S_WaitForProgram_onExit(void)
{
    DSPshowDelete(1, "");
    DCSdebugSystemInfo("Curent state: %s, Current event: %s", stateEnumToText[state], eventEnumToText[event]);   /// Debug info
}

void S_Process_Glass_onEntry(void)
{
    time_display();                    /// Displays the time selecion menu
    event_t time = setTime();          /// Call setTime function
    FSM_AddEvent(time);                /// Gets trigger from setTime function
}

void S_Process_Glass_onExit(void)
{
    DSPshowDelete(1, "");
    DCSdebugSystemInfo("Curent state: %s, Current event: %s", stateEnumToText[state], eventEnumToText[event]);   /// Debug info
}

void S_Process_Ceramic_onEntry(void)
{
    time_display();                    /// Displays the time selecion menu
    event_t time = setTime();          /// Call setTime function
    FSM_AddEvent(time);                /// Gets trigger from setTime function
}

void S_Process_Ceramic_onExit(void)
{
    DSPshowDelete(1, "");
    DCSdebugSystemInfo("Curent state: %s, Current event: %s", stateEnumToText[state], eventEnumToText[event]);   /// Debug info
}

void S_Process_Eco_onEntry(void)
{
    time_display();                    /// Displays the time selecion menu
    event_t time = setTime();          /// Call setTime function
    FSM_AddEvent(time);                /// Gets trigger from setTime function
}

void S_Process_Eco_onExit(void)
{
    DSPshowDelete(1, "");
    DCSdebugSystemInfo("Curent state: %s, Current event: %s", stateEnumToText[state], eventEnumToText[event]);   /// Debug info
}

void S_InsertedTime_onEntry(void)
{
    FSM_AddEvent(E_START_PROG); /// Starts the program
}

void S_InsertedTime_onExit(void)
{
    DSPshowDelete(1, "");
    DCSdebugSystemInfo("Curent state: %s, Current event: %s", stateEnumToText[state], eventEnumToText[event]);   /// Debug info
}

void S_StartProgram_onEntry(void)
{
    DSPshow(1, "Selected program: %s", selectedProgram);
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
    }
}

void S_StartProgram_onExit(void)
{
    DSPshowDelete(1, "");
    DCSdebugSystemInfo("Curent state: %s, Current event: %s", stateEnumToText[state], eventEnumToText[event]);   /// Debug info
}

void S_RestartProgram_onEntry(void)
{
    DSPshow(1, "Restarting");
    strcpy(selectedProgram, "none");
    selectedTime = 0;
    FSM_AddEvent(E_RETURN);
}

void S_RestartProgram_onExit(void)
{
    DSPshowDelete(1, "");
    DCSdebugSystemInfo("Curent state: %s, Current event: %s", stateEnumToText[state], eventEnumToText[event]);   /// Debug info
}

void S_ShutdownSystem(int status)
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
        strcpy(selectedProgram, "GLASS");
        break;
    case '2':
        program = E_CERAM;
        strcpy(selectedProgram, "CERAMIC");
        break;
    case '3':
        program = E_ECO;
        strcpy(selectedProgram, "ECO");
        break;
    case 'C':
        program = E_RESTART_PROGRAM;
        strcpy(selectedProgram, "none");
        break;
    default:
        DSPshow(1, "This character is not known");
        strcpy(selectedProgram, "none");
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
}

/// Helper functions
/// Displays the menu text for the time selection display
void time_display(void)
{
    DSPshow(1, "Selected program: %s", selectedProgram);

    DSPshow(3, "Enter desired time:     Current selected time is: %d", selectedTime );
    DSPshow(4, "<1> Add 60 minutes.     <4> Add 60 minutes + more.");
    DSPshow(5, "<2> Add 10 minutes.     <5> Add 10 minutes + more.");
    DSPshow(6, "<3> Add 5 minutes.      <6> Add 5  minutes + more.");

    DSPshow(8, "Press <ENTER> to start program");
    DSPshow(9, "Press <C> to cancel");
}

/// simulate delay in miliseconds
void delay_ms(uint32_t d)
{
    DCSdebugSystemInfo("Delay waiting for %d micro-seconds", d);
    sleep(d/1000);
}
