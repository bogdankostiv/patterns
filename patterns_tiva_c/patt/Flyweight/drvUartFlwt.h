/**
 * @file drvUartFlwt.h
 * @author bogdan.kostiv
 * @date 3.08.2018
 *
 * @brief
 */

#ifndef PATT_DRVUARTFLWT_H_
#define PATT_DRVUARTFLWT_H_


#include "errTypes.h"
#include "patt/Flyweight/drvUartFlwtDefs.h"

/**
 * @brief Uart initialization
 *
 * @param pInst Pointer on an instance.
 * @param port Enum for port's selection.
 *
 * @return Error code.
 */
err_t drvUartFlwt_Init(drvUart_t* pInst, drvUart_FlwtFab_t port);

/**
 * @brief Setting UART's configuration
 *
 * @param pInst Pointer on an instance.
 * @param pConfig Pointer on a config.
 */
void drvUartFlwt_SetConf(drvUart_t* pInst, const drvUartConf_t* pConfig);

/**
 * @brief Blocking writing to UART
 *
 * @param pInst Pointer on an instance.
 * @param pData Pointer on data buffer.
 * @param size Bytes count.
 *
 * @return Error code.
 */
err_t drvUartFlwt_Write(drvUart_t* pInst, const uint8_t* pData, uint16_t size);

/**
 * @brief Blocking reading from UART
 *
 * @param pInst Pointer on an instance.
 * @param pData Pointer on data buffer.
 * @param size Bytes count.
 *
 * @return Error code.
 */
err_t drvUartFlwt_Read(drvUart_t* pInst, uint8_t* pData, uint16_t size);


#endif /* PATT_DRVUARTFLWT_H_ */
