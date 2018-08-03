/*
 * drvUartFlwtDefs.h
 *
 *  Created on: 3 ρεπο. 2018 π.
 *      Author: bogdan.kostiv
 */

#ifndef PATT_DRVUARTFLWTDEFS_H_
#define PATT_DRVUARTFLWTDEFS_H_

#include <stdint.h>

typedef enum
{
    DRVUART_UART0 = 0,
    DRVUART_UART1,
    DRVUART_AMOUNT
} drvUart_FlwtFab_t;

typedef enum
{
    DRVUART_PARITY_NONE,
    DRVUART_PARITY_EVEN,
    DRVUART_PARITY_ODD,
    DRVUART_PARITY_ONE,
    DRVUART_PARITY_ZERO,
    DRVUART_PARITY_AMOUNT,
}drvUart_Parity_t;

typedef enum
{
    DRVUART_FRAME_5,
    DRVUART_FRAME_6,
    DRVUART_FRAME_7,
    DRVUART_FRAME_8,
    DRVUART_FRAME_AMOUNT,
}drvUart_Frame_t;

typedef enum
{
    DRVUART_STOPBIT_1,
    DRVUART_STOPBIT_2,
    DRVUART_STOPBIT_AMOUNT,
}drvUart_StopBit_t;

typedef struct
{
    uint32_t sysCrtlUartAddr;
    uint32_t sysCrtlTxRxPortAddr;
    uint32_t gpiotxPinConfig;
    uint32_t gpiorxPinConfig;
    uint32_t gpioRxTxPortAddr;
    uint32_t gpioRxTxPinMap;
    uint32_t uartBaseaddr;
    uint32_t uartDefBaudrate;
    drvUart_Parity_t uartDefParity;
    drvUart_Frame_t uartDefFrame;
    drvUart_StopBit_t uartDefStopBit;
}drvUart_Flwt_t;

typedef struct
{
    drvUart_Flwt_t uartFlwt;
    uint32_t baudRate;
    drvUart_Parity_t parity;
    drvUart_Frame_t frameSize;
    drvUart_StopBit_t stopBit;
}drvUart_t;


#endif /* PATT_DRVUARTFLWTDEFS_H_ */
