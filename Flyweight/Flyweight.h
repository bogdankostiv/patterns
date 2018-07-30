#ifndef FLYWEIGHT_H_INCLUDED
#define FLYWEIGHT_H_INCLUDED

#include "FlyweightDefs.h"

void Fw_Init(Fw_t *inst, FwOpt_t opt);

void Fw_Action(Fw_t *inst);

void Fw_ActionWitFn(Fw_t *inst);

#endif // FLYWEIGHT_H_INCLUDED
