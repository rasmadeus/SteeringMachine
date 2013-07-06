#ifndef WITHBACKLINK_H
#define WITHBACKLINK_H

#include "../RudderPlay.h"

class WithBackLink : public RudderPlay
{
    Q_OBJECT
public:
    explicit WithBackLink(QObject *parent = 0);
    void firstStep(const double& in);
};

#endif // WITHBACKLINK_H
