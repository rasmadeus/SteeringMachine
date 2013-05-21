#ifndef AMPLITUDEPHASEFREQUENCY_H
#define AMPLITUDEPHASEFREQUENCY_H

#include <QTextStream>
struct APF
{
    double w;      //2 * PI * f
    double lgW;    //lg(w)
    double A;      //Aout / Ain
    double lgA;    //20 * lg(A)
    double dt;
    double dPhase; //dt * f * 360

    APF()
    {
        w = lgW = A = lgA = dt = dPhase = 0;
    }

    static void writeHeader(QTextStream& stream)
    {
        stream << "w lgW Aout/Ain 20*lg(Aout/Ain) dt dt*f*360\r\n";
    }

    void writeData(QTextStream& stream) const
    {
        stream << w << " " << lgW << " " << A << " " << lgA << " " << dt << " " << dPhase <<"\r\n";
    }
};

#include <QVector>
class AmplitudePhaseFrequency
{
public:

    static APF getAPF(
        const QVector<double>& t,
        const QVector<double>& in,
        const QVector<double>& out,
        const double& A,
        const double& f
    );

private:

    static void fill(
        const QVector<double>& t,
        const QVector<double>& in,
        const QVector<double>& out,
              QVector<double>& minOut,
              QVector<double>& maxOut,
              QVector<double>& tInMax,
              QVector<double>& tOutMax
    );

    static void level(
        QVector<double>& minOut,
        QVector<double>& maxOut,
        QVector<double>& tInMax,
        QVector<double>& tOutMax
    );

    static void level(
        QVector<double>& values,
        int n
    );

    static double getAverage(
        const QVector<double>& first,
        const QVector<double>& second
    );

    static void removeFirstElements(
       QVector<double>& values
    );

    static void fill(
       APF& result,
       const QVector<double>& minOut,
       const QVector<double>& maxOut,
       const QVector<double>& tInMax,
       const QVector<double>& tOutMax,
       const double& A,
       const double& f
    );
};

#endif // AMPLITUDEPHASEFREQUENCY_H
