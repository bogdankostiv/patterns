/**
 * @file drvUartFlwt.c
 * @author bogdan.kostiv
 * @date 3.08.2018
 *
 * @brief
 */

#include <stddef.h>
#include <stdbool.h>
#include "assert.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/uart.h"
#include "patt/Flyweight/drvUartFlwtFactory.h"
#include "patt/Flyweight/drvUartFlwt.h"

static const uint32_t drvUart_ParityTable[DRVUART_PARITY_AMOUNT] =
{
     UART_CONFIG_PAR_NONE,  /**< DRVUART_PARITY_NONE*/
     UART_CONFIG_PAR_EVEN,  /**< DRVUART_PARITY_EVEN*/
     UART_CONFIG_PAR_ODD,   /**< DRVUART_PARITY_ODD*/
     UART_CONFIG_PAR_ONE,   /**< DRVUART_PARITY_ONE*/
     UART_CONFIG_PAR_ZERO   /**< DRVUART_PARITY_ZERO*/
};

static const uint32_t drvUart_FrameTable[DRVUART_FRAME_AMOUNT] =
{
     UART_CONFIG_WLEN_5,    /**< DRVUART_FRAME_5*/
     UART_CONFIG_WLEN_6,    /**< DRVUART_FRAME_6*/
     UART_CONFIG_WLEN_7,    /**< DRVUART_FRAME_7*/
     UART_CONFIG_WLEN_8     /**< DRVUART_FRAME_8*/
};

static const uint32_t drvUart_StopbitTable[DRVUART_STOPBIT_AMOUNT] =
{
    UART_CONFIG_STOP_ONE,   /**< DRVUART_STOPBIT_1*/
    UART_CONFIG_STOP_TWO    /**< DRVUART_STOPBIT_2*/
};

err_t drvUartFlwt_Init(drvUart_t* pInst, drvUart_FlwtFab_t port)
{
    err_t res = ERR_OK;

    ASSERT(NULL != pInst);

    const drvUart_Flwt_t * uartFlwt = drvUartFlwtFactory_GetFlwt(port);

    do
    {
        if (NULL == uartFlwt)
        {
            res = ERR_UART_INIT;
            break;
        }

        pInst->uartBaseaddr = uartFlwt->uartBaseaddr;

        // Enable the peripherals
        SysCtlPeripheralEnable(uartFlwt->sysCrtlUartAddr);
        SysCtlPeripheralEnable(uartFlwt->sysCrtlTxRxPortAddr);

        // Configure the GPIO pin muxing for the UART function.
        GPIOPinConfigure(uartFlwt->gpiorxPinConfig);
        GPIOPinConfigure(uartFlwt->gpiotxPinConfig);

        // Since GPIOs are used for the UART function, they must be
        // configured for use as a peripheral function (instead of GPIO).
        GPIOPinTypeUART(uartFlwt->gpioRxTxPortAddr, uartFlwt->gpioRxTxPinMap);

        drvUartFlwt_SetConf(pInst, &uartFlwt->defaultConfig);
    } while (false);

    return res;
}

void drvUartFlwt_SetConf(drvUart_t* pInst, const drvUartConf_t * pConfig)
{

    ASSERT(NULL != pInst);
    ASSERT(NULL != pConfig);

    memcpy(&pInst->config, pConfig, sizeof(pInst->config));

    // Configure the UART for default operation.
#if defined(TARGET_IS_TM4C129_RA0) ||                                         \
    defined(TARGET_IS_TM4C129_RA1) ||                                         \
    defined(TARGET_IS_TM4C129_RA2)
    UARTConfigSetExpClk(pInst->uartBaseaddr, SysCtlClockGet(), pInst->config.baudRate,
                        (drvUart_ParityTable[pInst->config.parity] |
                         drvUart_FrameTable[pInst->config.frameSize]  |
                         drvUart_StopbitTable[pInst->config.stopBit] ));
#else
    UARTConfigSetExpClk(pInst->uartBaseaddr, SysCtlClockGet(), pInst->config.baudRate,
                        (drvUart_ParityTable[pInst->config.parity] |
                         drvUart_FrameTable[pInst->config.frameSize]  |
                         drvUart_StopbitTable[pInst->config.stopBit] ));
#endif
}

err_t drvUartFlwt_Write(drvUart_t* pInst, const uint8_t *pData, uint16_t size)
{
    uint16_t i;

    ASSERT(NULL != pInst);
    ASSERT(NULL != pData);

    for (i = 0; i < size; i++)
    {
        UARTCharPut(pInst->uartBaseaddr, pData[i]);
    }

    return ERR_OK;
}

err_t drvUartFlwt_Read(drvUart_t* pInst, uint8_t *pData, uint16_t size)
{
    uint16_t i;

    ASSERT(NULL != pInst);
    ASSERT(NULL != pData);

    for (i = 0; i < size; i++)
    {
        pData[i] = (uint8_t) UARTCharGet(pInst->uartBaseaddr);
    }

    return ERR_OK;
}
