#include "OutMaker.h"

#include "child/SteeringMachine.h"
#include "child/NewAntiBlendFilter.h"
Output* OutMaker::make(Type type, QObject* parent)
{
    if(type == STEERING_MACHINE)
        return new SteeringMachine(parent);
    return new NewAntiBlendFilter(parent);
}

#include <QComboBox>
void OutMaker::fill(QComboBox* cb)
{
    cb->addItem(QObject::tr("Привод ПГ-22 М"), STEERING_MACHINE);
    cb->addItem(QObject::tr("Новый антиизгибный фильтр"), NEW_ANTIBLEND_FILTER);
}
