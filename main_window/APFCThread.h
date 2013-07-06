#ifndef APFCTHREAD_H
#define APFCTHREAD_H

#include <QThread>

class Output;
class APFC;
class Input;
class QSettings;

class APFCThread : public QThread
{
    Q_OBJECT
public:
    APFCThread(QObject *parent = 0);
    void setOutput(Output* out);
    void setInput(Input* in);
    void setAPFC(APFC* apfc);
    void restoreReportDir(QSettings& settings);
    void saveReportDir(QSettings& settings);
    bool reportDirIsEmpty() const;
    const QString& getReportDir() const;
public slots:
    void setReportDir(const QString& reportDir);
protected:
    void run();
private:
    QString reportDir;
    APFC* apfc;
    Input* in;
    Output* out;
};

#endif // APFCTHREAD_H
