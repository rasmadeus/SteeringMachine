#include "OutMaker.h"

#include "child/SteeringMachine.h"
#include "child/NewAntiBlendFilter.h"
#include "child/rudder_play_child/WithBackLink.h"
#include "child/rudder_play_child/WithoutBackLink.h"
#include "child/rudder_play_child/WithoutBackLinkSave.h"
#include "child/OscillatoryLink.h"
Output* OutMaker::make(Type type, QObject* parent)
{
    switch((int) type){
        case STEERING_MACHINE       : return new SteeringMachine(parent);
        case NEW_ANTIBLEND_FILTER   : return new NewAntiBlendFilter(parent);
        case WITH_BACK_LINK         : return new WithBackLink(parent);
        case WITHOUT_BACK_LINK      : return new WithoutBackLink(parent);
        case WITHOUT_BACK_LINK_SAVE : return new WithoutBackLinkSave(parent);
        default                     : return new OscillatoryLink(parent);
    }
}

#include <QComboBox>
void OutMaker::fill(QComboBox* cb)
{
    cb->addItem(QObject::tr(""), STEERING_MACHINE);
    cb->addItem(QObject::tr(""), NEW_ANTIBLEND_FILTER);
    cb->addItem(QObject::tr(""), WITHOUT_BACK_LINK);
    cb->addItem(QObject::tr(""), WITH_BACK_LINK);
    cb->addItem(QObject::tr(""), WITHOUT_BACK_LINK_SAVE);
    cb->addItem(QObject::tr("Колебательное звено"), OSCILLARY_LINK);
}
