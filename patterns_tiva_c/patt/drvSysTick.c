/**
 * @file SysTickDrv.c
 * @author bogdan.kostiv
 * @date 3.07.2016
 *
 * @brief
 */

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "assert.h"
#include "driverlib/systick.h"
#include "driverlib/sysctl.h"
#include "patt/drvSysTick.h"

#define	SYSTICK_FREQUENCY	(1000u)		//set 1ms systick period

volatile static sysTickTime_t time = 0;
volatile static bool isInit = false;
static sysTickCb_t* sysTickCb = NULL;

static void SysTickHandler(void);
static sysTickCb_t* drvSysTick_GetLastCbNode(void);

static void SysTickHandler(void)
{
    sysTickCb_t * node  = sysTickCb;
    sysTickCbFn fn;

	time++;

	if (NULL != node)
	{
	    while ((NULL != node->fn))
	    {
	        fn = node->fn;
	        (*fn)();
	        node = node->next;
	        if (NULL == node)
	        {
	            break;
	        }
	    }
	}
}

void drvSysTick_Init()
{
    if (false == isInit)
    {
        SysTickEnable();
        SysTickPeriodSet(SysCtlClockGet()/SYSTICK_FREQUENCY);
        SysTickIntRegister(&SysTickHandler);

        time = 0;
        isInit = true;
    }
}

void drvSysTick_registerExtCb(sysTickCb_t* cb)
{
    sysTickCb_t * node  = drvSysTick_GetLastCbNode();

    ASSERT(NULL != cb);

    cb->next = NULL;
    if (NULL != cb->fn)
    {
        if (NULL == node)
        {
            sysTickCb = cb;
        }
        else
        {
            node->next = cb;
        }
    }

}

sysTickTime_t drvSysTick_GetTime()
{
	ASSERT(false != isInit);

	return time;
}

bool drvSysTick_IsTimePassed(sysTickTime_t savedTime, sysTickTime_t period)
{
    ASSERT(false != isInit);

	if ((time - savedTime) >= period)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void drvSysTick_DelayMs(sysTickTime_t delay)
{
    sysTickTime_t startTime = drvSysTick_GetTime();

    ASSERT(false != isInit);

    while (true != drvSysTick_IsTimePassed(startTime, delay))
    {
        asm(" NOP");
    }
}

static sysTickCb_t* drvSysTick_GetLastCbNode(void)
{
    sysTickCb_t * node  = sysTickCb;

    if (NULL != node)
    {
        if (NULL != node->fn)
        {
            while (NULL != node->next)
            {
                node = node->next;
            }
        }
    }

    return node;
}
