#include "WithoutBackLink.h"

WithoutBackLink::WithoutBackLink(QObject* parent) :
    RudderPlay(parent)
{
}

double WithoutBackLink::lastStep()
{
    return rudderPlay.PlayRudder(output);
}
