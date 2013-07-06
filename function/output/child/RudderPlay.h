#ifndef RUDDERPLAY_H
#define RUDDERPLAY_H

#include "SteeringMachine.h"
#include "rudder_play/CRudderPlay.h"

class RudderPlay : public SteeringMachine
{
    Q_OBJECT
public:
    explicit RudderPlay(QObject *parent = 0);
    void reset();
    bool setData(const QModelIndex &index, const QVariant &value, int role);
protected:
    CRudderPlay rudderPlay;
};

#endif // RUDDERPLAY_H
