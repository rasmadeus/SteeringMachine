#ifndef WITHOUTBACKLINKSAVE_H
#define WITHOUTBACKLINKSAVE_H

#include "../RudderPlay.h"

class WithoutBackLinkSave : public RudderPlay
{
    Q_OBJECT
public:
    explicit WithoutBackLinkSave(QObject *parent = 0);
    double lastStep();
};

#endif // WITHOUTBACKLINKSAVE_H
