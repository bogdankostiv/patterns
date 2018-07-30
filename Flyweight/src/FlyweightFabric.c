#include "FlyweightFabric.h"

static void FwFabricFnDefault(void);
static void FwFabricFn0(void);
static void FwFabricFn1(void);

static Fw_t FwFabricDefault = {
    .field1 = 255,
    .fn1 = FwFabricFnDefault
};

static Fw_t FwFabric[FW_OPT_DEFAULT] = {
    { .field1 = 0, .fn1 = FwFabricFn0},
    { .field1 = 1, .fn1 = FwFabricFn1}
};

Fw_t * FwFabric_Get(FwOpt_t opt)
{
    Fw_t *res = &FwFabricDefault;

    if (FW_OPT_DEFAULT > opt)
    {
        res = &FwFabric[opt];
    }

    return res;
}

static void FwFabricFnDefault(void)
{
    printf("FlyWeight test: FwFabricFnDefault\n");
}

static void FwFabricFn0(void)
{
    printf("FlyWeight test: FwFabricFn0\n");
}

static void FwFabricFn1(void)
{
    printf("FlyWeight test: FwFabricFn1\n");
}
