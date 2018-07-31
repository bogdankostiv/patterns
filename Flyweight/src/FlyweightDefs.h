#ifndef FLYWEIGHTDEFS_H_INCLUDED
#define FLYWEIGHTDEFS_H_INCLUDED

#include <stdint.h>

typedef enum
{
    FW_OPT_0 = 0,
    FW_OPT_1,
    FW_OPT_DEFAULT
}FwOpt_t;

typedef void (*FwFunct) (void);

typedef struct {
    uint8_t field1;
    FwFunct funct;
} FwFabric_t;

typedef struct {
    FwFabric_t FwFabric;
    // other fields
} Fw_t;

#endif // FLYWEIGHTDEFS_H_INCLUDED
