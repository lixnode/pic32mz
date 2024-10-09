/* 
 * File:   systick.h
 * Author: lixnode
 *
 * Created on October 9, 2024, 10:21 PM
 */

#ifndef SYSTICK_H
#define	SYSTICK_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

#define CORETIMER_IN_MS()   (CORE_TIMER_FREQUENCY / 1000U)    
#define CORETIMER_IN_US()   (CORETIMER_IN_MS() / 1000U)    

void SysTick_Init();    
uint32_t SysTick_GetCount();
uint32_t SysTick_GetMillis();
uint32_t SysTick_GetMicros();
    
#ifdef	__cplusplus
}
#endif

#endif	/* SYSTICK_H */

