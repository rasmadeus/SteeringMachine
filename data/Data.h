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
    void setInterval(const double& xMin, const double& xMax);
    APF getAPF(const double& A, const double& f);
private:
    void clear();
    void calculate();
private:
    static const double step;
    double xMin, xMax;
    Function* out;
    Function* in;
    QVector<double> argValues;
    QVector<double> inValues;
    QVector<double> outValues;
};

#endif // DATA_H
