#include <string.h>
#include "Flyweight.h"

void Fw_Init(Fw_t *inst, FwOpt_t opt)
{
    Fw_t *FwReceived = FwFabric_Get(opt);
    memcpy(inst, FwReceived, sizeof(*inst));
}

void Fw_Action(Fw_t *inst)
{
    printf("FlyWeight test: %d\n", inst->field1);
}

void Fw_ActionWitFn(Fw_t *inst)
{
    inst->fn1();
}
