#ifndef AMPLITUDEPHASEFREQUENCY_H
#define AMPLITUDEPHASEFREQUENCY_H

#include <QTextStream>
struct APF
{
    APF();
    APF(double f, double Ain, double Aout, double dt);

    static void writeHeader(QTextStream& stream);
    void writeData(QTextStream& stream) const;

    double w;      //2 * PI * f
    double lgW;    //lg(w)
    double A;      //Aout / Ain
    double lgA;    //20 * lg(A)
    double dt;
    double dPhase; //dt * f * 360
};

#include <QVector>
class AmplitudePhaseFrequency
{
public:

    static APF getAPF(
        const QVector<double>& in,
        const QVector<double>& out,
        const double& A,
        const double& f,
        const double& step
    );    

    static double getAverage(const QVector<double>& values);
    static double max(const QVector<double>& values);
    static double min(const QVector<double>& values);
    static double getCorrelationAnalysis(double T, double step, const QVector<double>& in, const QVector<double>& out);

};

#endif // AMPLITUDEPHASEFREQUENCY_H
