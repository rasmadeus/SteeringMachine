#include "APFCThread.h"
#include "data/APFC.h"
#include "function/input/Input.h"
#include "../function/output/Output.h"

APFCThread::APFCThread(QObject *parent) :
    QThread(parent)
{
    in = 0;
    out = 0;
    apfc = 0;
}

void APFCThread::run()
{
    if(out && in && apfc && !reportDir.isEmpty()){
        out->reset();
        apfc->save(reportDir);
    }
}

void APFCThread::setOutput(Output* out)
{
    this->out = out;
}

void APFCThread::setInput(Input* in)
{
    this->in = in;
}

void APFCThread::setAPFC(APFC* apfc)
{
    this->apfc = apfc;
}

#include <QSettings>
void APFCThread::saveReportDir(QSettings& settings)
{
    settings.setValue("reportDir", reportDir);
}

void APFCThread::restoreReportDir(QSettings& settings)
{
    reportDir = settings.value("reportDir").toString();
}

bool APFCThread::reportDirIsEmpty() const
{
    return reportDir.isEmpty();
}

const QString& APFCThread::getReportDir() const
{
    return reportDir;
}

#include <QFileDialog>
void APFCThread::setReportDir(const QString& reportDir)
{
    this->reportDir = reportDir;
}
