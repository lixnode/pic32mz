#include "systick.h"


// Private memebers
static bool _SysTick_Is_Init;
volatile static uint32_t _SysTick_Total_Millis;
static uint32_t _SysTick_Total_Millis_Stored;
volatile static uint32_t _SysTick_Total_Micros;
static uint32_t _SysTick_Total_Micros_Stored;


void SysTick_Init()
{
    if (!_SysTick_Is_Init) {
        _SysTick_Total_Millis = 0;
        _SysTick_Total_Millis_Stored = 0;
        _SysTick_Total_Micros = 0;
        _SysTick_Total_Micros_Stored = 0;
        // Init complete
        _SysTick_Is_Init = true;
    }
}

uint32_t SysTick_GetCount()
{
    return CORETIMER_CounterGet();
}


uint32_t SysTick_GetMillis()
{
    if (_SysTick_Total_Millis < UINT32_MAX) {
        if ((SysTick_GetCount() - _SysTick_Total_Millis_Stored) >= CORETIMER_IN_MS()) {
            _SysTick_Total_Millis_Stored = SysTick_GetCount();
            _SysTick_Total_Millis++;
        }
    }
    else {
        _SysTick_Total_Millis = 0;
        _SysTick_Total_Millis_Stored = 0;
    }
    return _SysTick_Total_Millis;
}

uint32_t SysTick_GetMicros()
{
    if (_SysTick_Total_Micros < UINT32_MAX) {
        if ((SysTick_GetCount() - _SysTick_Total_Micros_Stored) >= CORETIMER_IN_US()) {
            _SysTick_Total_Micros_Stored = SysTick_GetCount();
            _SysTick_Total_Micros++;
        }
    }
    else {
        _SysTick_Total_Micros = 0;
        _SysTick_Total_Micros_Stored = 0;
    }
    return _SysTick_Total_Micros;
}
