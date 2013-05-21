#ifndef STEERINGMACHINE_H
#define STEERINGMACHINE_H

#include "../Function.h"

class SteeringMachine : public Function
{
public:
    SteeringMachine();
    void reset();
    void setForsek1(const double& Forsek1);
    const double& getForsek1() const;
    double out(const double& in);
    void setK1(const double& K1);
    void setT1(const double& T1);
    void setT2(const double& T2);
    void setKsi1(const double& ksi1);
    void setKsi2(const double& ksi2);
    void setOgr(const double& Ogr);
    void setKf(const double& kf);
    const double& getK1() const;
    const double& getT1() const;
    const double& getT2() const;
    const double& getKsi1() const;
    const double& getKsi2() const;
    const double& getOgr() const;
    const double& getKf() const;
private:
    void init();
private:
    double Forsek1;
    double K1, T1, T2, ksi1, ksi2, Ogr;
    double kF;

    double output;
    double X1, X2, X3, X4;

    const double dT;
};

#endif // STEERINGMACHINE_H
