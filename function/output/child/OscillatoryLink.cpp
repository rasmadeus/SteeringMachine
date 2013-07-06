#include "OscillatoryLink.h"
#include "../../../data/Data.h"
OscillatoryLink::OscillatoryLink(QObject *parent):
    Output(parent)
{
    args << QPair<QString, double>("T", 0.012);
    args << QPair<QString, double>("ksi", 0.9);
}

void OscillatoryLink::reset()
{
    dx2 = dx1 = 0;
    output = 0;
}

double OscillatoryLink::out(const double& in)
{
    dx2 = (in - output - 2 * T() * ksi() * dx1) / T() / T();
    dx1    += dx2 * step;
    output += dx1 * step;
    return output;
}

double OscillatoryLink::T() const
{
    return args[0].second;
}

double OscillatoryLink::ksi() const
{
    return args[1].second;
}
