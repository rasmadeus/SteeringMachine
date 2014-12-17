#ifndef STEERINGMACHINE_H
#define STEERINGMACHINE_H

#include "../Output.h"

class SteeringMachine: public Output
{
public:
    explicit SteeringMachine(QObject *parent = 0);
    double out(const double &in);
    void reset();
protected:
    const double& Forsek1() const;
    const double& kF() const;
    const double& K1() const;
    const double& T1() const;
    const double& T2() const;
    const double& ksi1() const;
    const double& ksi2() const;
    double Ogr() const;
protected:
    virtual void firstStep(const double& in);
    virtual void middleStep();
    virtual double lastStep();
protected:
    double output;
    double X1, X2, X3, X4;
};

#endif // STEERINGMACHINE_H
