#ifndef OSCILLATORYLINK_H
#define OSCILLATORYLINK_H

#include "../Output.h"

class OscillatoryLink : public Output
{
    Q_OBJECT
public:
    explicit OscillatoryLink(QObject *parent = 0);
    void reset();
    double out(const double& in);
    double T() const;
    double ksi() const;
private:
    double dx2;
    double dx1;
    double output;

};

#endif // OSCILLATORYLINK_H
