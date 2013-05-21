#include "Input.h"

void Input::setAmplitude(const double& A)
{
    this->A = A;
}

void Input::setFrequency(const double& f)
{
    this->f = f;
}

const double& Input::getAmplitude() const
{
    return A;
}

const double& Input::getFrequency() const
{
    return f;
}

#include <qmath.h>
double Input::out(const double& in)
{
    return A * sin( 2* M_PI * f * in );
}
