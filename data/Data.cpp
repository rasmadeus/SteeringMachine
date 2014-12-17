#include "Data.h"

Data::Data()
{
    out = in = 0;
}

void Data::setOut(Function* out)
{
    this->out = out;
}

void Data::setIn(Function* in)
{
    this->in = in;
}

#include "../function/Function.h"
#include <qmath.h>
void Data::calculate(const double& f)
{
    clear();

    double step = 0.0002;

    double k = (0.0001 - step)/(15 - 0.15);
    double b = step - k * 0.15;

    step = f < 15 ? k * f + b : 0.0001;

    in->setStep(step);
    out->setStep(step);

    for(double x = 0; x <= (f < 1 ? 0.1 : 10/f); x += step){
        inValues  << in->out(x);
        outValues << out->out(inValues.last());
    }
}

APF Data::getAPF(const double& A, const double& f, const double& step)
{
    calculate(f);
    return AmplitudePhaseFrequency::getAPF(inValues, outValues, A, f, step);
}

void Data::clear()
{
    inValues.clear();
    outValues.clear();
}
