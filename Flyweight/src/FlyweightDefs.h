#ifndef FLYWEIGHTDEFS_H_INCLUDED
#define FLYWEIGHTDEFS_H_INCLUDED

#include <stdint.h>

typedef enum
{
    FW_OPT_0 = 0,
    FW_OPT_1,
    FW_OPT_DEFAULT
}FwOpt_t;

typedef void (*FwFn) (void);

typedef struct {
    uint8_t field1;
    FwFn fn1;
} Fw_t;

#endif // FLYWEIGHTDEFS_H_INCLUDED
