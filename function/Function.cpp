#include "Function.h"

Function::Function()
{
    step = 0.001;
}

Function::~Function()
{
}

void Function::setStep(double step)
{
    this->step = step;
}

const double& Function::getStep() const
{
    return step;
}
