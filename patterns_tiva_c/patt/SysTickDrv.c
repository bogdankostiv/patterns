/**
 * @file SysTickDrv.c
 * @author bogdan.kostiv
 * @date 3.07.2016
 *
 * @brief
 */

#include <stdint.h>
#include <stdbool.h>
#include "assert.h"
#include "driverlib/systick.h"
#include "driverlib/sysctl.h"
#include "patt/SysTickDrv.h"

#define	SYSTICK_FREQUENCY	(1000u)		//set 1ms systick period

volatile static sysTickTime_t time = 0;
volatile static bool isInit = false;

static void SysTickHandler(void);

static void SysTickHandler(void)
{
	time++;
}

void SysTickDrv_Init()
{

    SysTickEnable();
    SysTickPeriodSet(SysCtlClockGet()/SYSTICK_FREQUENCY);
    SysTickIntRegister(&SysTickHandler);

    time = 0;
    isInit = true;
}

sysTickTime_t SysTickDrv_GetTime()
{
	ASSERT(false != isInit);

	return time;
}

bool SysTickDrv_IsTimePassed(sysTickTime_t savedTime, sysTickTime_t period)
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

void SysTickDrv_DelayMs(sysTickTime_t delay)
{
    sysTickTime_t startTime = SysTickDrv_GetTime();

    while (true != SysTickDrv_IsTimePassed(startTime, delay))
    {
        asm("NOP");
    }
}
