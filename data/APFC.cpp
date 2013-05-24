#include "APFC.h"

#include "../function/input/Input.h"

APFC::APFC()
{
    minF = 1;
    maxF = 70;
    stepF = 1;
    minA = 0.5/57.3;
    maxA = 2/57.3;
    stepA = 0.5/57.3;

    in = 0;
    out = 0;
    data = new Data();
}

APFC::~APFC()
{
    delete data;
}

void APFC::setInput(Input* in)
{
    this->in = in;
    data->setIn(in);
}

void APFC::setOutput(Function *out)
{
    this->out = out;
    data->setOut(out);
}

void APFC::setIntervalF(const double& minF, const double& maxF, const double& stepF)
{
    this->minF = minF;
    this->maxF = maxF;
    this->stepF = stepF;
}

void APFC::setIntervalA(const double& minA, const double& maxA, const double& stepA)
{
    this->minA = minA/57.3;
    this->maxA = maxA/57.3;
    this->stepA = stepA/57.3;
}

#include <QFile>
#include <QTextStream>
void APFC::save(const QString& dir)
{
    fill();
    for(int i=0; i<apfc.size(); ++i){
        QFile file(dir + QString("/A=%1.txt").arg(57.3*(minA + i*stepA)));
        if(!file.open(QFile::WriteOnly)){
            file.close();
            continue;
        }
        QTextStream stream(&file);
        APF::writeHeader(stream);
        for(int j=0; j<apfc[i].size(); ++j){
            apfc[i][j].writeData(stream);
        }
        file.close();
    }
}

void APFC::fill()
{
    apfc.clear();  
    QVector<APF> apf;
    for(double a = minA; a <= maxA; a += stepA){
        in->setAmplitude(a);
        for(double f = minF; f <= maxF; f += stepF){
            in->setFrequency(f);
            apf << data->getAPF(in->getAmplitude(), in->getFrequency());
        }
        apfc << apf;
        apf.clear();
    }
}
