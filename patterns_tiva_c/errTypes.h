/*
 * errTypes.h
 *
 *  Created on: 3 ρεπο. 2018 π.
 *      Author: bogdan.kostiv
 */

#ifndef ERRTYPES_H_
#define ERRTYPES_H_

#include <stdint.h>

typedef int32_t err_t;

#define ERR_OK                  ((err_t) 0)
#define ERR_GENERAL             ((err_t) -1)

#define ERR_UART_GENERAL        ((err_t) -10)
#define ERR_UART_INIT           ((err_t) (ERR_UART_GENERAL - 1))


#endif /* ERRTYPES_H_ */
