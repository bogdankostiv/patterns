#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "errTypes.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "patt/drvSysTick.h"
#include "patt/ulTimer.h"
#include "patt/Flyweight/drvUartFlwt.h"

drvUart_t uart0;
drvUart_t uart1;

timer_t timer1;
timer_t timer2;

void initClocks(void);
void timer1Fn(void* ctx);
void timer2Fn(void* ctx);

void initClocks(void)
{
#if defined(TARGET_IS_TM4C129_RA0) ||                                         \
    defined(TARGET_IS_TM4C129_RA1) ||                                         \
    defined(TARGET_IS_TM4C129_RA2)
    uint32_t ui32SysClock;
#endif

    // Set the clocking to run directly from the external crystal/oscillator.
    // TODO: The SYSCTL_XTAL_ value must be changed to match the value of the
    // crystal on your board.
#if defined(TARGET_IS_TM4C129_RA0) ||                                         \
    defined(TARGET_IS_TM4C129_RA1) ||                                         \
    defined(TARGET_IS_TM4C129_RA2)
    ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
                                       SYSCTL_OSC_MAIN |
                                       SYSCTL_USE_OSC), 25000000);
#else
    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                   SYSCTL_XTAL_16MHZ);
#endif
}

void timer1Fn(void* ctx)
{
    char strUart0[] = "UART0 test\r\n";

    drvUartFlwt_Write(&uart0, (uint8_t*) strUart0, strlen(strUart0));
}

void timer2Fn(void* ctx)
{
    char strUart1[] = "UART1 test\r\n";

    drvUartFlwt_Write(&uart1, (uint8_t*) strUart1, strlen(strUart1));
}

int main(void)
{



    initClocks();

    drvSysTick_Init();

    ulTimer_Init();

    drvUartFlwt_Init(&uart0, DRVUART_UART0);
    drvUartFlwt_Init(&uart1, DRVUART_UART1);

    ulTimer_Create(&timer1, &timer1Fn, NULL, 1000, true);
    ulTimer_Create(&timer2, &timer2Fn, NULL, 2000, true);

    while (1)
    {


        //drvSysTick_DelayMs(1000);

        ulTimer_Run();
    }
}
