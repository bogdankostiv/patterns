#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "errTypes.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "patt/SysTickDrv.h"
#include "patt/Flyweight/drvUartFlwt.h"

drvUart_t uart0;
drvUart_t uart1;

void initClocks(void);

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


int main(void)
{
    char strUart0[] = "UART0 test\r\n";
    char strUart1[] = "UART1 test\r\n";

    initClocks();

    SysTickDrv_Init();

    drvUartFlwt_Init(&uart0, DRVUART_UART0);
    drvUartFlwt_Init(&uart1, DRVUART_UART1);

    while (1)
    {
        drvUartFlwt_Write(&uart0, (uint8_t*) strUart0, strlen(strUart0));
        drvUartFlwt_Write(&uart1, (uint8_t*) strUart1, strlen(strUart1));
        SysTickDrv_DelayMs(1000);
    }
}
