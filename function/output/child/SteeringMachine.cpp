#include "SteeringMachine.h"

const double SteeringMachine::dT;

#include <QPair>
#include <QVector>
SteeringMachine::SteeringMachine(QObject* parent):
    Output(
        QVector<QPair<QString, double> > () <<
                QPair<QString, double>("Forsek1", 2.87)   <<
                QPair<QString, double>("kF",      0.0069) <<
                QPair<QString, double>("K1",      36.792) <<
                QPair<QString, double>("T1",      0.002)  <<
                QPair<QString, double>("T2",      0.002)  <<
                QPair<QString, double>("ksi1",    0.2)    <<
                QPair<QString, double>("ksi2",    0.2)    <<
                QPair<QString, double>("Ogr",     240),
        parent
    )
{    
}


const double& SteeringMachine::Forsek1() const
{
    return args[0].second;
}

const double& SteeringMachine::kF() const
{
    return args[1].second;
}

const double& SteeringMachine::K1() const
{
    return args[2].second;
}

const double& SteeringMachine::T1() const
{
    return args[3].second;
}

const double& SteeringMachine::T2() const
{
    return args[4].second;
}

const double& SteeringMachine::ksi1() const
{
    return args[5].second;
}

const double& SteeringMachine::ksi2() const
{
    return args[6].second;
}

const double& SteeringMachine::Ogr() const
{
    return args[7].second;
}

#include <qmath.h>
double SteeringMachine::out(const double &in)
{
    X1 = in - output;

    for(int j=0; j<5; ++j)
    {
        double kf   = fabs(X1) < kF() ? Forsek1() : 1;
        double dX2  = (kf*K1()*X1 - X2) / T2();
        double dX3  = X4;
        double dX4  = (2*(ksi2()-ksi1())*T1()*X2-X3)/T1()/T1()-2*ksi2()/T1()*X4;
        double X5   = 0.5*(fabs(X2 - X3 + Ogr()) - fabs(X2 - X3 - Ogr()));
        X2     += dX2*dT;
        X3     += dX3*dT;
        X4     += dX4*dT;
        output += X5 *dT;
    }
    return output;
}

void SteeringMachine::reset()
{
    output = X1 = X2 = X3 = X4 = 0;
}
