#ifndef INPUT_H
#define INPUT_H

#include "../Function.h"

class Input : public Function
{
public:
    void setFrequency(const double& f);
    void setAmplitude(const double& A);
    const double& getFrequency() const;
    const double& getAmplitude() const;
    double out(const double& in);
private:
    double f;
    double A;
};

#endif // INPUT_H
