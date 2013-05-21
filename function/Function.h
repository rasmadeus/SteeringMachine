#ifndef FUNCTION_H
#define FUNCTION_H

class Function
{
public:
    virtual ~Function();
    virtual double out(const double& in) = 0;
};

#endif // FUNCTION_H
