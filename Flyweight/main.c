#include <stdio.h>
#include <stdlib.h>

#include "FlyweightDefs.h"
#include "Flyweight.h"

Fw_t FlyWeight0, FlyWeight1, FlyWeightX;


int main()
{
    printf("Hello world!\n");

    Fw_Init(&FlyWeight0, FW_OPT_0);
    Fw_Init(&FlyWeight1, FW_OPT_1);
    Fw_Init(&FlyWeightX, FW_OPT_DEFAULT);

    Fw_Action(&FlyWeight0);
    Fw_Action(&FlyWeight1);
    Fw_Action(&FlyWeightX);

    Fw_ActionWitFn(&FlyWeight0);
    Fw_ActionWitFn(&FlyWeight1);
    Fw_ActionWitFn(&FlyWeightX);

    return 0;
}
