#include "Data.h"

const double Data::step = 0.001;

Data::Data()
{
    out = in = 0;
    xMin = 0;
    xMax = 5;
}

void Data::setOut(Function* out)
{
    this->out = out;
}

void Data::setIn(Function* in)
{
    this->in = in;
}

void Data::setInterval(const double& xMin, const double& xMax)
{
    this->xMin = xMin;
    this->xMax = xMax;
}

#include "../function/Function.h"
void Data::calculate()
{
    clear();

    for(double x = xMin; x <= xMax; x += step){
        argValues << x;
        inValues  << in->out(x);
        outValues << out->out(inValues.last());
    }
}

APF Data::getAPF(const double& A, const double& f)
{
    calculate();
    return AmplitudePhaseFrequency::getAPF(argValues, inValues, outValues, A, f);
}

void Data::clear()
{
    argValues.clear();
    inValues.clear();
    outValues.clear();
}
