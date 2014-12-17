#include <QApplication>
#include <QFileDialog>
#include "../function/input/Input.h"
#include "../function/steering_machine/SteeringMachine.h"
#include "../data/APFC.h"

int main(int argc, char** argv)
{
    QApplication SteeringMachineTest(argc, argv);
    Input in;
    SteeringMachine out;
    APFC apfc(&in, &out);

    QString dir = QFileDialog::getExistingDirectory();
    if(!dir.isEmpty()) apfc.save(dir);

    return SteeringMachineTest.exec();
}
