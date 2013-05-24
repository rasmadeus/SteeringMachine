#ifndef APFC_H
#define APFC_H

class Input;

#include "AmplitudePhaseFrequency.h"
#include "Data.h"
#include <QString>

class APFC
{
public:
    APFC();
    ~APFC();
    void setInput(Input* in);
    void setOutput(Function* out);
    void setIntervalF(const double& minF, const double& maxF, const double& stepF);
    void setIntervalA(const double& minA, const double& maxA, const double& stepA);
    void save(const QString& dir);
private:
    void fill();
private:
    double minF, maxF, stepF;
    double minA, maxA, stepA;
    QVector<QVector<APF> >apfc;
    Input* in;
    Function* out;
    Data* data;
};

#endif // APFC_H
