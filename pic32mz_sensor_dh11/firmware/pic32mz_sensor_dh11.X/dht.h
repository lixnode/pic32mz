/* 
 * File:   dht.h
 * Author: lixnode
 *
 * Created on October 9, 2024, 10:11 PM
 */

#ifndef DHT_H
#define	DHT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

    typedef enum {
        AUTO_DETECT,
                DHT11,
                DHT12,
                AM2302,  // Packaged DHT22
                RHT03    // Equivalent to DHT22
    } DHT_MODEL_t;

    typedef enum {
        ERROR_NONE,
                ERROR_TIMEOUT,
                ERROR_CHECKSUM
    } DHT_ERROR_t;
    
    void DHT_Setup(uint32_t pin, DHT_MODEL_t model);
    void DHT_ResetTimer();
    double DHT_GetTemperature();
    double DHT_GetHumidity();
    
    DHT_ERROR_t DHT_GetStatus();
    const char* DHT_GetStatusString();

#ifdef	__cplusplus
}
#endif

#endif	/* DHT_H */

