#include "WithoutBackLinkSave.h"

WithoutBackLinkSave::WithoutBackLinkSave(QObject* parent) :
    RudderPlay(parent)
{
}


double WithoutBackLinkSave::lastStep()
{
    output = rudderPlay.PlayRudder(output);
    return output;
}
