/*
 * drvUartFlwtFabric.c
 *
 *  Created on: 3 ρεπο. 2018 π.
 *      Author: bogdan.kostiv
 */

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"
#include "patt/drvUartFlwtFabric.h"

static const drvUart_Flwt_t drvUartFlwtFabric_Data [DRVUART_AMOUNT] =
{
 {
  .sysCrtlUartAddr = SYSCTL_PERIPH_UART0,
  .sysCrtlTxRxPortAddr = SYSCTL_PERIPH_GPIOA,
  .gpiotxPinConfig = GPIO_PA1_U0TX,
  .gpiorxPinConfig = GPIO_PA0_U0RX,
  .gpioRxTxPortAddr = GPIO_PORTA_BASE,
  .gpioRxTxPinMap = GPIO_PIN_0 | GPIO_PIN_1,
  .uartBaseaddr = UART0_BASE,
  .uartDefBaudrate = UART_DEFAULT_BAUDRATE,
  .uartDefParity = UART_DEFAULT_PARITY,
  .uartDefFrame = UART_DEFAULT_FRAME,
  .uartDefStopBit = UART_DEFAULT_STOPBIT
 }

};

const drvUart_Flwt_t * drvUartFlwtFabric_GetFlwt(drvUart_FlwtFab_t port)
{
    const drvUart_Flwt_t * ret = NULL;

    if (DRVUART_AMOUNT > port)
    {
        ret = &drvUartFlwtFabric_Data[port];
    }

    return ret;
}
