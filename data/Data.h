#ifndef DATA_H
#define DATA_H

class Input;
class Function;

#include <QVector>
#include "AmplitudePhaseFrequency.h"

class Data
{
public:
    Data();
    void setOut(Function* out);
    void setIn(Function* in);
    APF getAPF(const double& A, const double& f, const double& step);
private:
    void clear();
    void calculate(const double& f);
private:
    Function* out;
    Function* in;
    QVector<double> inValues;
    QVector<double> outValues;
};

#endif // DATA_H
