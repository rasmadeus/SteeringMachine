#include "RudderPlay.h"

RudderPlay::RudderPlay(QObject* parent) :
    SteeringMachine(parent)
{
    args << QPair<QString, double>("Free play", 1);
}

void RudderPlay::reset()
{
    rudderPlay.SetValue(0);
    SteeringMachine::reset();
}

#include <qmath.h>
bool RudderPlay::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if(!Output::setData(index, value, role)){
        return false;
    }
    if(index.row() == 8){
        rudderPlay.SetFreePlay(value.toDouble() / 60 * M_PI / 180);
    }
    return true;
}
