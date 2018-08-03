/*
 * assert.h
 *
 *  Created on: 3 ρεπο. 2018 π.
 *      Author: bogdan.kostiv
 */

#ifndef ASSERT_H_
#define ASSERT_H_

#include <stdint.h>
#include "common.h"

#if 0 < DEBUG
#define ASSERT(cond) if(0 == (cond))           \
    {                                          \
         assert_fn(__FILE__, __LINE__);        \
    }
#else
#define ASSERT(cond) (void)(cond);
#endif

void assert_fn(char* module, int32_t line);

#endif /* ASSERT_H_ */
