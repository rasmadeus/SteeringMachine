#include "SteeringMachine.h"

#include <QPair>
#include <QVector>
SteeringMachine::SteeringMachine(QObject* parent):
    Output(parent)
{    
    args <<
    QPair<QString, double>("Forsek1", 0)    <<
    QPair<QString, double>("kF",      0) <<
    QPair<QString, double>("K1",      0) <<
    QPair<QString, double>("T1",      0)  <<
    QPair<QString, double>("T2",      0) <<
    QPair<QString, double>("ksi1",    0)    <<
    QPair<QString, double>("ksi2",    0)    <<
    QPair<QString, double>("Ogr",     0);
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

double SteeringMachine::Ogr() const
{
    return !args[7].second ? 0 : args[7].second;
}


void SteeringMachine::firstStep(const double &in)
{
    X1 = in - output;
}

#include <qmath.h>
void SteeringMachine::middleStep()
{
   //implementation was removed
}

double SteeringMachine::lastStep()
{
    return output;
}

double SteeringMachine::out(const double &in)
{
    firstStep(in);
    middleStep();
    return lastStep();
}

void SteeringMachine::reset()
{
    output = X1 = X2 = X3 = X4 = 0;
}
