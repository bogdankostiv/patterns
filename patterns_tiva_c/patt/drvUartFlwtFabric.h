/*
 * drvUartFlwtFabric.h
 *
 *  Created on: 3 ρεπο. 2018 π.
 *      Author: bogdan.kostiv
 */

#ifndef PATT_DRVUARTFLWTFABRIC_H_
#define PATT_DRVUARTFLWTFABRIC_H_

#include "patt/drvUartFlwtDefs.h"

#define UART_DEFAULT_BAUDRATE   9600
#define UART_DEFAULT_PARITY     DRVUART_PARITY_NONE
#define UART_DEFAULT_FRAME      DRVUART_FRAME_8
#define UART_DEFAULT_STOPBIT    DRVUART_STOPBIT_1

const drvUart_Flwt_t * drvUartFlwtFabric_GetFlwt(drvUart_FlwtFab_t port);

#endif /* PATT_DRVUARTFLWTFABRIC_H_ */
