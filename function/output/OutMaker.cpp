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
    cb->addItem(QObject::tr("������ ��-22 �"), STEERING_MACHINE);
    cb->addItem(QObject::tr("����� ������������ ������"), NEW_ANTIBLEND_FILTER);
}
