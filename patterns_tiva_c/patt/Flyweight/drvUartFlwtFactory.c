/**
 * @file drvUartFlwtFabric.c
 * @author bogdan.kostiv
 * @date 3.08.2018
 *
 * @brief
 */

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "patt/Flyweight/drvUartFlwtFactory.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"

/**
 * @brief Array of structures for flyweight
 *
 * @note This array should be extended with required values for proper ports
 */
static const drvUart_Flwt_t drvUartFlwtFactory_Data [DRVUART_AMOUNT] =
{
    /**
    * UART0
    */
    {
        .sysCrtlUartAddr = SYSCTL_PERIPH_UART0,
        .sysCrtlTxRxPortAddr = SYSCTL_PERIPH_GPIOA,
        .gpiotxPinConfig = GPIO_PA1_U0TX,
        .gpiorxPinConfig = GPIO_PA0_U0RX,
        .gpioRxTxPortAddr = GPIO_PORTA_BASE,
        .gpioRxTxPinMap = GPIO_PIN_0 | GPIO_PIN_1,
        .uartBaseaddr = UART0_BASE,
        .defaultConfig =
        {
            .baudRate = UART_DEFAULT_BAUDRATE,
            .parity = UART_DEFAULT_PARITY,
            .frameSize = UART_DEFAULT_FRAME,
            .stopBit = UART_DEFAULT_STOPBIT
        }
    },

    /**
     * UART1
     */
    {
        .sysCrtlUartAddr = SYSCTL_PERIPH_UART1,
        .sysCrtlTxRxPortAddr = SYSCTL_PERIPH_GPIOB,
        .gpiotxPinConfig = GPIO_PB1_U1TX,
        .gpiorxPinConfig = GPIO_PB0_U1RX,
        .gpioRxTxPortAddr = GPIO_PORTB_BASE,
        .gpioRxTxPinMap = GPIO_PIN_0 | GPIO_PIN_1,
        .uartBaseaddr = UART1_BASE,
        .defaultConfig =
        {
            .baudRate = UART_DEFAULT_BAUDRATE,
            .parity = UART_DEFAULT_PARITY,
            .frameSize = UART_DEFAULT_FRAME,
            .stopBit = UART_DEFAULT_STOPBIT
        }
    },

};

const drvUart_Flwt_t* drvUartFlwtFactory_GetFlwt(drvUart_FlwtFab_t port)
{
    const drvUart_Flwt_t * ret = NULL;

    if (DRVUART_AMOUNT > port)
    {
        ret = &drvUartFlwtFactory_Data[port];
    }

    return ret;
}
