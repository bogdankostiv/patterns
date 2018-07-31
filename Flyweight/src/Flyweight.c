#include <stdio.h>
#include <string.h>
#include "FlyweightFabric.h"
#include "Flyweight.h"

void Fw_Init(Fw_t *inst, FwOpt_t opt)
{
    FwFabric_t *FwFabricReceived = FwFabric_Get(opt);
    memcpy(&inst->FwFabric, FwFabricReceived, sizeof(inst->FwFabric));
}

void Fw_Action(Fw_t *inst)
{
    printf("FlyWeight test: %d\n", inst->FwFabric.field1);
}

void Fw_ActionWitFn(Fw_t *inst)
{
    inst->FwFabric.funct();
}
