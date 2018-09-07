/**
 * @file SysTickDrv.c
 * @author bogdan.kostiv
 * @date 3.07.2016
 *
 * @brief
 */

#ifndef DL_SYSTICKDRV_H_
#define DL_SYSTICKDRV_H_

#include <stdbool.h>
#include <stdint.h>

typedef uint32_t sysTickTime_t;

typedef void (*sysTickCbFn) (void);

typedef struct sysTickCbNode
{
    sysTickCbFn fn;
    struct sysTickCbNode * next;
} sysTickCb_t;

void drvSysTick_Init(void);

void drvSysTick_registerExtCb(sysTickCb_t* cb);

sysTickTime_t drvSysTick_GetTime(void);

bool drvSysTick_IsTimePassed(sysTickTime_t savedTime, sysTickTime_t period);

void drvSysTick_DelayMs(sysTickTime_t delay);

#endif /* DL_SYSTICKDRV_H_ */
