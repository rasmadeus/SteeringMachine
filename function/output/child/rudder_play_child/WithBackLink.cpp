#include "WithBackLink.h"

WithBackLink::WithBackLink(QObject* parent) :
    RudderPlay(parent)
{
}

void WithBackLink::firstStep(const double& in)
{
    X1 = in - rudderPlay.PlayRudder(output);
}
