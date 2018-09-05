/**
 * @file drvUartFlwtFabric.h
 * @author bogdan.kostiv
 * @date 3.08.2018
 *
 * @brief
 */

#ifndef PATT_DRVUARTFLWTFACTORY_H_
#define PATT_DRVUARTFLWTFACTORY_H_

#include "patt/Flyweight/drvUartFlwtDefs.h"

/**
 * @brief Default UART configurations
 */
#define UART_DEFAULT_BAUDRATE   9600
#define UART_DEFAULT_PARITY     DRVUART_PARITY_NONE
#define UART_DEFAULT_FRAME      DRVUART_FRAME_8
#define UART_DEFAULT_STOPBIT    DRVUART_STOPBIT_1

/**
 * @brief Flyweight's factory function
 *
 * @param port Enum for port's selection.
 *
 * @return Pointer on factory object.
 */
const drvUart_Flwt_t* drvUartFlwtFactory_GetFlwt(drvUart_FlwtFab_t port);

#endif /* PATT_DRVUARTFLWTFACTORY_H_ */
