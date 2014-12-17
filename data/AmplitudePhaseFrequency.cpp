#include "AmplitudePhaseFrequency.h"

#include <QDebug>
APF AmplitudePhaseFrequency::getAPF(
    const QVector<double>& in,
    const QVector<double>& out,
    const double& A,
    const double& f,
    const double& step
)
{
    return in.size() < 3 ? APF() : APF(f, A, getAverage(out), getCorrelationAnalysis(1/f, step, in, out));
}

double AmplitudePhaseFrequency::max(const QVector<double>& values)
{
    if(values.isEmpty()){
        return 0;
    }
    double max = values[0];
    for(int i=1; i<values.size(); ++i){
        if(values[i] > max){
            max = values[i];
        }
    }
    return max;
}

double AmplitudePhaseFrequency::min(const QVector<double>& values)
{
    if(values.isEmpty()){
        return 0;
    }
    double min = values[0];
    for(int i=1; i<values.size(); ++i){
        if(values[i] < min){
            min = values[i];
        }
    }
    return min;
}


double AmplitudePhaseFrequency::getCorrelationAnalysis(double T, double step, const QVector<double>& in, const QVector<double>& out)
{
    double max = 0;
    double t   = 0;

    for(int j = 0; j < qMin(in.size(), (int) (T/step)); ++j){
        double summ = 0;
        for(int i=0; i< in.size() - j; ++i){
            summ = (summ*i + in[i]*out[i+j])/(i+1);
        }
        if(summ > max){
            max = summ;
            t = j * step;
        }
    }

    return t;
}

double AmplitudePhaseFrequency::getAverage(const QVector<double>& values)
{
    return 0.5 * (max(values) - min(values));
}
