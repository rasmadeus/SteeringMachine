#include "Sinus.h"

Sinus::Sinus(QObject *parent) :
    Output(parent)
{
}

void Sinus::reset()
{

}

double Sinus::out(const double& in)
{
    return in;
}
