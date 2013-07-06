#ifndef SINUS_H
#define SINUS_H

#include "../Output.h"

class Sinus : public Output
{
    Q_OBJECT
public:
    explicit Sinus(QObject *parent = 0);
    void reset();
    double out(const double& in);

};

#endif // SINUS_H
