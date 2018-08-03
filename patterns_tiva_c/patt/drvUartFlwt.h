/*
 * drvUartFlwt.h
 *
 *  Created on: 3 ρεπο. 2018 π.
 *      Author: bogdan.kostiv
 */

#ifndef PATT_DRVUARTFLWT_H_
#define PATT_DRVUARTFLWT_H_


#include "errTypes.h"
#include "patt/drvUartFlwtDefs.h"

err_t drvUartFlwt_Init(drvUart_t* pInst, drvUart_FlwtFab_t port);

err_t drvUartFlwt_SetConf(drvUart_t* pInst, drvUart_FlwtFab_t port);

err_t drvUartFlwt_Write(drvUart_t* pInst, uint8_t *data, uint16_t size);

err_t drvUartFlwt_Read(drvUart_t* pInst, uint8_t *data, uint16_t size);


#endif /* PATT_DRVUARTFLWT_H_ */
