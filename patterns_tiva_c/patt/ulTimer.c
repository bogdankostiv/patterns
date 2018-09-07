/**
 * @file ulTimer.ñ
 * @author bogdan.kostiv
 * @date 7.09.2018
 *
 * @brief
 */

#include <string.h>
#include "assert.h"
#include "patt/ulTimer.h"
#include "patt/drvSysTick.h"

typedef struct
{
    timer_t* timers;
    bool needUpdate;
    bool isInited;
    sysTickCb_t sysTickCb;
} timerCtr_t;

static timerCtr_t timerCtr = {0};

static void ulTimer_SchedulerCb(void);
static timer_t* ulTimer_GetLastNode(void);
static void ulTimer_AddNode(timer_t* node);

void ulTimer_Init(void)
{
    timerCtr.needUpdate = true;
    timerCtr.isInited = true;

    timerCtr.sysTickCb.fn = &ulTimer_SchedulerCb;
    drvSysTick_registerExtCb(&timerCtr.sysTickCb);
}

void ulTimer_Create(timer_t* timer, const timerFn timerFn, void* ctx, uint32_t period, bool runTimer)
{
    ASSERT(NULL != timer);
    ASSERT(NULL != timerFn);
    ASSERT(0 != period);

    timer->timer.timerFn = timerFn;
    timer->timer.lastTriggerTime = drvSysTick_GetTime();
    timer->timer.ctx = ctx;
    timer->timer.period = period;
    timer->timer.isrunning = runTimer;

    ulTimer_AddNode(timer);
}

bool ulTimer_IsRunning(timer_t* timer)
{
    ASSERT(NULL != timer);

    return timer->timer.isrunning;
}

void ulTimer_Suspend(timer_t* timer)
{
    ASSERT(NULL != timer);

    timer->timer.isrunning = false;
}

void ulTimer_Resume(timer_t* timer)
{
    ASSERT(NULL != timer);

    timer->timer.isrunning = true;
}

void ulTimer_Delete(timer_t* timer)
{
    ASSERT(NULL != timer);

    ulTimer_Suspend(timer);
    //

}

void ulTimer_Run(void)
{
    static timer_t * currentTimerNode = NULL;

    if (true == timerCtr.needUpdate)
    {
        if (NULL != currentTimerNode)
        {
            bool triggerTimer = drvSysTick_IsTimePassed(currentTimerNode->timer.lastTriggerTime,
                                                        currentTimerNode->timer.period);
            timerFn timerFn = currentTimerNode->timer.timerFn;
            if (triggerTimer && (NULL != timerFn))
            {
                (*timerFn)(currentTimerNode->timer.ctx);
                currentTimerNode->timer.lastTriggerTime = drvSysTick_GetTime();
            }

            currentTimerNode = timerCtr.timers->next;
        }
        else
        {
            currentTimerNode = timerCtr.timers;
            timerCtr.needUpdate = false;
        }
    }
}

static void ulTimer_SchedulerCb(void)
{
    timerCtr.needUpdate = true;
}

static timer_t* ulTimer_GetLastNode(void)
{
    timer_t* node  = timerCtr.timers;

    if (NULL != node)
    {
        while (NULL != node->next)
        {
            node = node->next;
        }
    }

    return node;
}

static void ulTimer_AddNode(timer_t* node)
{
    timer_t* lastNode = ulTimer_GetLastNode();

    node->next = NULL;

    if(NULL == lastNode)
    {
        timerCtr.timers = node;
    }
    else
    {
        lastNode->next = node;
    }
}
