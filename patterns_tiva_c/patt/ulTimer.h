/**
 * @file ulTimer.h
 * @author bogdan.kostiv
 * @date 7.09.2018
 *
 * @brief
 */

#ifndef PATT_ULTIMER_H_
#define PATT_ULTIMER_H_

#include <stdint.h>
#include <stdbool.h>
#include "patt/drvSysTick.h"

typedef void (*timerFn)(void * ctx);

typedef struct {
    timerFn timerFn;
    sysTickTime_t lastTriggerTime;
    void* ctx;
    uint32_t period;
    bool isrunning;
}timerData_t;

typedef struct timerNode
{
    timerData_t timer;
    struct timerNode * next;
} timer_t;

void ulTimer_Init(void);

void ulTimer_Create(timer_t* timer, const timerFn timerFn, void* ctx, uint32_t period, bool runTimer);

bool ulTimer_IsRunning(timer_t* timer);

void ulTimer_Suspend(timer_t* timer);

void ulTimer_Resume(timer_t* timer);

void ulTimer_Delete(timer_t* timer);

void ulTimer_Run(void);

#endif /* PATT_ULTIMER_H_ */
