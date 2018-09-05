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

void SysTickDrv_Init(void);

sysTickTime_t SysTickDrv_GetTime(void);

bool SysTickDrv_IsTimePassed(sysTickTime_t savedTime, sysTickTime_t period);

void SysTickDrv_DelayMs(sysTickTime_t delay);

#endif /* DL_SYSTICKDRV_H_ */
