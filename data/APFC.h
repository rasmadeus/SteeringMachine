#ifndef APFC_H
#define APFC_H

class Input;
class QProgressBar;

#include "AmplitudePhaseFrequency.h"
#include "Data.h"
#include <QString>

#include <QObject>

class APFC: public QObject
{
    Q_OBJECT
public:
    explicit APFC(QObject* parent = 0);
    ~APFC();
    void setInput(Input* in);
    void setOutput(Function* out);
    void setIntervalF(const double& minF, const double& maxF, const double& stepF);
    void setIntervalA(const double& minA, const double& maxA, const double& stepA);
    void save(const QString& dir);
signals:
    void wasAmplitudeStep(int value);
    void wasFrequencyStep(int value);
private:
    void fill();
private:
    double minF, maxF, stepF;
    double minA, maxA, stepA;
    QVector<QVector<APF> >apfc;
    Input* in;
    Function* out;
    Data* data;
    QProgressBar* aPB;
    QProgressBar* fPB;
};

#endif // APFC_H
