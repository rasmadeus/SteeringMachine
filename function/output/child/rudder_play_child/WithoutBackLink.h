#ifndef WITHOUTBACKLINK_H
#define WITHOUTBACKLINK_H

#include "../RudderPlay.h"

class WithoutBackLink : public RudderPlay
{
    Q_OBJECT
public:
    explicit WithoutBackLink(QObject *parent = 0);
    double lastStep();
};

#endif // WITHOUTBACKLINK_H
