#include "AmplitudePhaseFrequency.h"

APF::APF(){
    w = lgW = A = lgA = dt = dPhase = 0;
}

#include <qmath.h>
APF::APF(double f, double Ain, double Aout, double dt)
{
    w = 2 * M_PI * f;
    lgW = log10(w);
    A = Aout/Ain;
    lgA = 20 * log10(A);
    this->dt = dt;
    dPhase = - dt*f*360;
}

#include <QTextStream>
void APF::writeHeader(QTextStream& stream)
{
    stream << "w lgW Aout/Ain 20*lg(Aout/Ain) dt dt*f*360\r\n";
}

void APF::writeData(QTextStream& stream) const
{
    stream << w << " " << lgW << " " << A << " " << lgA << " " << dt << " " << dPhase <<"\r\n";
}
