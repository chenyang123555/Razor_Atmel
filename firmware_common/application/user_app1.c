/**********************************************************************************************************************
File: user_app1.c                                                                

----------------------------------------------------------------------------------------------------------------------
To start a new task using this user_app1 as a template:
 1. Copy both user_app1.c and user_app1.h to the Application directory
 2. Rename the files yournewtaskname.c and yournewtaskname.h
 3. Add yournewtaskname.c and yournewtaskname.h to the Application Include and Source groups in the IAR project
 4. Use ctrl-h (make sure "Match Case" is checked) to find and replace all instances of "user_app1" with "yournewtaskname"
 5. Use ctrl-h to find and replace all instances of "UserApp1" with "YourNewTaskName"
 6. Use ctrl-h to find and replace all instances of "USER_APP1" with "YOUR_NEW_TASK_NAME"
 7. Add a call to YourNewTaskNameInitialize() in the init section of main
 8. Add a call to YourNewTaskNameRunActiveState() in the Super Loop section of main
 9. Update yournewtaskname.h per the instructions at the top of yournewtaskname.h
10. Delete this text (between the dashed lines) and update the Description below to describe your task
----------------------------------------------------------------------------------------------------------------------

Description:
This is a user_app1.c file template 

------------------------------------------------------------------------------------------------------------------------
API:

Public functions:


Protected System functions:
void UserApp1Initialize(void)
Runs required initialzation for the task.  Should only be called once in main init section.

void UserApp1RunActiveState(void)
Runs current task state.  Should only be called once in main loop.


**********************************************************************************************************************/

#include "configuration.h"

/***********************************************************************************************************************
Global variable definitions with scope across entire project.
All Global variable names shall start with "G_UserApp1"
***********************************************************************************************************************/
/* New variables */
volatile u32 G_u32UserApp1Flags;                       /* Global state flags */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Existing variables (defined in other files -- should all contain the "extern" keyword) */
extern volatile u32 G_u32SystemFlags;                  /* From main.c */
extern volatile u32 G_u32ApplicationFlags;             /* From main.c */

extern volatile u32 G_u32SystemTime1ms;                /* From board-specific source file */
extern volatile u32 G_u32SystemTime1s;                 /* From board-specific source file */


/***********************************************************************************************************************
Global variable definitions with scope limited to this local application.
Variable names shall start with "UserApp1_" and be declared as static.
***********************************************************************************************************************/
static fnCode_type UserApp1_StateMachine;            /* The state machine function pointer */
//static u32 UserApp1_u32Timeout;                      /* Timeout counter used across states */


/**********************************************************************************************************************
Function Definitions
**********************************************************************************************************************/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Public functions                                                                                                   */
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Protected functions                                                                                                */
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
Function: UserApp1Initialize

Description:
Initializes the State Machine and its variables.

Requires:
  -

Promises:
  - 
*/
void UserApp1Initialize(void)
{
 LedOff(WHITE);
  LedOff(PURPLE);
  LedOff(BLUE);
  LedOff(CYAN);
  LedOff(GREEN);
  LedOff(YELLOW);
  LedOff(ORANGE);
  LedOff(RED);
  PWMAudioSetFrequency(BUZZER1, 416);
  PWMAudioSetFrequency(BUZZER2, 624);
  /* If good initialization, set state to Idle */
  if( 1 )
  {
    UserApp1_StateMachine = UserApp1SM_Idle;
  }
  else
  {
    /* The task isn't properly initialized, so shut it down and don't run */
    UserApp1_StateMachine = UserApp1SM_Error;
  }

} /* end UserApp1Initialize() */

  
/*----------------------------------------------------------------------------------------------------------------------
Function UserApp1RunActiveState()

Description:
Selects and runs one iteration of the current state in the state machine.
All state machines have a TOTAL of 1ms to execute, so on average n state machines
may take 1ms / n to execute.

Requires:
  - State machine function pointer points at current state

Promises:
  - Calls the function to pointed by the state machine function pointer
*/
void UserApp1RunActiveState(void)
{
  UserApp1_StateMachine();

} /* end UserApp1RunActiveState */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Private functions                                                                                                  */
/*--------------------------------------------------------------------------------------------------------------------*/


/**********************************************************************************************************************
State Machine Function Definitions
**********************************************************************************************************************/

/*-------------------------------------------------------------------------------------------------------------------*/
/* Wait for ??? */
static void UserApp1SM_Idle(void)
{
if(WasButtonPressed(BUTTON1) ){
   if(WasButtonPressed(BUTTON2) ){
    if(WasButtonPressed(BUTTON0) ){
  //ButtonAcknowledge(BUTTON0);
  static u16 u16BlinkCount=0;
  u16BlinkCount++;
  if(u16BlinkCount==100){
  LedOff(WHITE);
  LedOff(PURPLE);
  LedOff(BLUE);
  LedOff(CYAN);
  LedOff(GREEN);
  LedOff(YELLOW);
  LedOff(ORANGE);
  LedOff(RED);
  }
  
  
  
  if(u16BlinkCount==600){
  
  LedOn(WHITE);
  LedOn(RED);
  LCDMessage(LINE1_START_ADDR, ">");
  LCDMessage(LINE2_START_ADDR, ">");
  LCDMessage(LINE1_END_ADDR, "<");
  LCDMessage(LINE2_END_ADDR, "<");
  
  PWMAudioOn(BUZZER1);
  PWMAudioOff(BUZZER2);
  }
  if(u16BlinkCount==1200){
  PWMAudioOff(BUZZER1);
  PWMAudioOn(BUZZER2);
  LCDMessage(LINE1_START_ADDR + 1, ">");
  LCDMessage(LINE2_START_ADDR + 1, ">");
  LCDMessage(LINE1_START_ADDR + 18, "<");
  LCDMessage(LINE2_START_ADDR + 18, "<");
  }
   if(u16BlinkCount==1800){
  LedOn(PURPLE);
  LedOn(ORANGE);
  PWMAudioOn(BUZZER1);
  PWMAudioOff(BUZZER2);
  LCDMessage(LINE1_START_ADDR + 6, "ambulance");
  
 
  
  }
  if(u16BlinkCount==2400){
  PWMAudioOff(BUZZER1);
  PWMAudioOn(BUZZER2);
  LCDMessage(LINE2_START_ADDR + 9, "120");
  }
  if(u16BlinkCount==3000){
  LedOn(BLUE);
  LedOn(YELLOW);
  PWMAudioOn(BUZZER1);
  PWMAudioOff(BUZZER2);
  }
  if(u16BlinkCount==3600){
  PWMAudioOff(BUZZER1);
  PWMAudioOn(BUZZER2);
  }
  if(u16BlinkCount==4200){
  LedOn(CYAN);
  LedOn(GREEN);
  PWMAudioOn(BUZZER1);
  PWMAudioOff(BUZZER2);
  }
  
  if(u16BlinkCount==4800){
  LedOff(CYAN);
  LedOff(GREEN);
  LedOff(BLUE);
  LedOff(YELLOW);
  LedOff(PURPLE);
  LedOff(ORANGE);
  LedOff(WHITE);
  LedOff(RED);
  PWMAudioOff(BUZZER1);
  PWMAudioOn(BUZZER2); 
  }
  if(u16BlinkCount==5400){
  LedBlink(WHITE, LED_8HZ);
  LedBlink(RED, LED_8HZ);
  PWMAudioOn(BUZZER1);
  PWMAudioOff(BUZZER2);
  }
  if(u16BlinkCount==6000){
    PWMAudioOff(BUZZER1);
  PWMAudioOn(BUZZER2);
  }
  if(u16BlinkCount==6600){
  PWMAudioOn(BUZZER1);
  PWMAudioOff(BUZZER2);
  }
  if(u16BlinkCount==7200){
  PWMAudioOff(BUZZER1);
  PWMAudioOn(BUZZER2);
  u16BlinkCount=0; 
  }
  
  }
  // if( IsButtonPressed(BUTTON1) ){
  else{
  LedOff(CYAN);
  LedOff(GREEN);
  LedOff(BLUE);
  LedOff(YELLOW);
  LedOff(PURPLE);
  LedOff(ORANGE);
  LedOff(WHITE);
  LedOff(RED);
  ///LCDCommand(LCD_CLEAR_CMD);
  PWMAudioOff(BUZZER1);
  PWMAudioOff(BUZZER2);
  }
  
  }
  }
  if(WasButtonPressed(BUTTON3) ){
    ButtonAcknowledge(BUTTON3);
  LedOff(CYAN);
  LedOff(GREEN);
  LedOff(BLUE);
  LedOff(YELLOW);
  LedOff(PURPLE);
  LedOff(ORANGE);
  LedOff(WHITE);
  LedOff(RED);
  PWMAudioOff(BUZZER1);
  PWMAudioOff(BUZZER2);
  }

} /* end UserApp1SM_Idle() */
    

/*-------------------------------------------------------------------------------------------------------------------*/
/* Handle an error */
static void UserApp1SM_Error(void)          
{
  
} /* end UserApp1SM_Error() */



/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File                                                                                                        */
/*--------------------------------------------------------------------------------------------------------------------*/
