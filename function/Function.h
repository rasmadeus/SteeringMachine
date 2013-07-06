#ifndef FUNCTION_H
#define FUNCTION_H

class Function
{
public:
    Function();
    virtual ~Function();
    virtual double out(const double& in) = 0;
    void setStep(double step);
    const double& getStep() const;
protected:
    double step;
};

#endif // FUNCTION_H
