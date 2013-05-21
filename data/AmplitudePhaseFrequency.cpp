#include "AmplitudePhaseFrequency.h"

APF AmplitudePhaseFrequency::getAPF(
    const QVector<double>& t,
    const QVector<double>& in,
    const QVector<double>& out,
    const double& A,
    const double& f
)
{
    APF result;
    if(t.size() < 3) return result;

    QVector<double> minOut, maxOut, tInMax, tOutMax;

    fill(t, in, out, minOut, maxOut, tInMax, tOutMax);
    level(minOut, maxOut, tInMax, tOutMax);

    fill(result, minOut, maxOut, tInMax, tOutMax, A, f);

    return result;
}

void AmplitudePhaseFrequency::fill(
    const QVector<double>& t,
    const QVector<double>& in,
    const QVector<double>& out,
          QVector<double>& minOut,
          QVector<double>& maxOut,
          QVector<double>& tInMax,
          QVector<double>& tOutMax
)
{
    for(int i = 1; i < t.size() - 1; ++i){
        if(out[i-1] > out[i] && out[i+1] > out[i]){
            minOut << out[i];
        }
        if(out[i-1] < out[i] && out[i+1] < out[i]){
            maxOut << out[i];
            tOutMax << t[i];
        }
        if(in[i-1] < in[i] && in[i+1] < in[i]){
            tInMax << t[i];
        }
    }
}

#include <qmath.h>
void AmplitudePhaseFrequency::level(
    QVector<double>& minOut,
    QVector<double>& maxOut,
    QVector<double>& tInMax,
    QVector<double>& tOutMax
)
{
    int n = qMin(minOut.size(), qMin(maxOut.size(), qMin(tInMax.size(), tOutMax.size())));
    level(minOut,  n);
    level(maxOut,  n);
    level(tInMax,  n);
    level(tOutMax, n);
    removeFirstElements(minOut);
    removeFirstElements(maxOut);
    removeFirstElements(tInMax);
    removeFirstElements(tOutMax);
}

void AmplitudePhaseFrequency::level(QVector<double>& values, int n)
{
    values.remove(n, values.size() - n);
}

void AmplitudePhaseFrequency::removeFirstElements(
    QVector<double>& values
)
{
    values.remove(0, 2);
}

double AmplitudePhaseFrequency::getAverage(
    const QVector<double>& first,
    const QVector<double>& second
)
{
    double summ = 0;
    for(int i=0; i<first.size(); ++i){
        summ += 0.5 * (second[i] - first[i]);
    }
    return summ / first.size();
}

void AmplitudePhaseFrequency::fill(
    APF& result,
    const QVector<double>& minOut,
    const QVector<double>& maxOut,
    const QVector<double>& tInMax,
    const QVector<double>& tOutMax,
    const double& A,
    const double& f
)
{

    result.w   = 2 * M_PI * f;
    result.lgW = log10(result.w);

    result.A = getAverage(minOut, maxOut) / A;
    result.lgA = 20 * log10(result.A);

    result.dt = getAverage(tOutMax, tInMax);
    result.dPhase = result.dt * f * 360;
    if (result.dPhase > 90) result.dPhase -= 180;
}
