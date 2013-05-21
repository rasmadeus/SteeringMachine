#include "SteeringMachine.h"

SteeringMachine::SteeringMachine():
    dT(0)
{
    reset();
    init();
}

void SteeringMachine::init()
{
    K1 = 0;
    T1 = T2 = 0;
    ksi1 = ksi2 = 0;
    Ogr = 0;

    Forsek1 = 0;
    kF = 0;
}

void SteeringMachine::reset()
{
    output = X1 = X2 = X3 = X4 = 0;
}

void SteeringMachine::setForsek1(const double& Forsek1)
{
    this->Forsek1 = Forsek1;
}

const double& SteeringMachine::getForsek1() const
{
    return Forsek1;
}

void SteeringMachine::setK1(const double &K1)
{
    this->K1 = K1;
}

void SteeringMachine::setKsi1(const double &ksi1)
{
    this->ksi1 = ksi1;
}

void SteeringMachine::setKsi2(const double &ksi2)
{
    this->ksi2 = ksi2;
}

void SteeringMachine::setT1(const double &T1)
{
    this->T1 = T1;
}

void SteeringMachine::setT2(const double &T2)
{
    this->T2 = T2;
}

void SteeringMachine::setOgr(const double &Ogr)
{
    this->Ogr = Ogr;
}

void SteeringMachine::setKf(const double &kF)
{
    this->kF = kF;
}

const double& SteeringMachine::getK1() const
{
    return K1;
}

const double& SteeringMachine::getKsi1() const
{
    return ksi1;
}

const double& SteeringMachine::getKsi2() const
{
    return ksi2;
}

const double& SteeringMachine::getT1() const
{
    return T1;
}

const double& SteeringMachine::getT2() const
{
    return T2;
}

const double& SteeringMachine::getOgr() const
{
    return Ogr;
}

const double& SteeringMachine::getKf() const
{
    return kF;
}
#include <qmath.h>
double SteeringMachine::out(const double& in)
{

    X1 = in - output;
    return output;
}
