/**
 * @file drvUartFlwtDefs.h
 * @author bogdan.kostiv
 * @date 3.08.2018
 *
 * @brief
 */

#ifndef PATT_DRVUARTFLWTDEFS_H_
#define PATT_DRVUARTFLWTDEFS_H_

#include <stdint.h>

/**
 * @brief Enum for object selection in fligweight
 */
typedef enum
{
    DRVUART_UART0 = 0,
    DRVUART_UART1,
    DRVUART_AMOUNT
} drvUart_FlwtFab_t;

/**
 * @brief Additional enums for HW configuration
 */
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

/**
 * @brief Configuration structure for UARTs
 */
typedef struct
{
    uint32_t baudRate;
    drvUart_Parity_t parity;
    drvUart_Frame_t frameSize;
    drvUart_StopBit_t stopBit;
}drvUartConf_t;

/**
 *@brief  Flyweight factory structure
 */
typedef struct
{
    uint32_t sysCrtlUartAddr;
    uint32_t sysCrtlTxRxPortAddr;
    uint32_t gpiotxPinConfig;
    uint32_t gpiorxPinConfig;
    uint32_t gpioRxTxPortAddr;
    uint32_t gpioRxTxPinMap;
    uint32_t uartBaseaddr;
    drvUartConf_t defaultConfig;
}drvUart_Flwt_t;

/**
 * @brief Basic structure for objects
 */
typedef struct
{
    uint32_t uartBaseaddr;
    drvUartConf_t config;
}drvUart_t;


#endif /* PATT_DRVUARTFLWTDEFS_H_ */
