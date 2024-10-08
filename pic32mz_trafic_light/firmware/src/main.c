/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes


#define goN   0
#define waitN 1
#define goE   2
#define waitE 3

struct State {
    uint32_t Out;
    uint32_t Wait;
    uint32_t Next[4];
};
typedef const struct State State_t;

State_t FMS[4] = {
    {0x21,3000,{goN,waitN,goN,waitN}},
    {0x22, 500,{goE,goE,goE,goE}},
    {0x0C,3000,{goE,goE,waitE,waitE}},
    {0x14, 500,{goN,goN,goN,goN}}
};
// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

uint32_t S;  // index to the current state
uint32_t Input;

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );

    S = goN; 
    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        LATH = FMS[S].Out;
        CORETIMER_DelayMs(FMS[S].Wait);
        Input = (PORTB >> 12) & 0x03;
        S = FMS[S].Next[Input];
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

