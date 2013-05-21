#ifndef VIEW_H
#define VIEW_H

#include <QDialog>
#include "function/input/Input.h"
#include "function/steering_machine/SteeringMachine.h"
#include "data/APFC.h"

namespace Ui {
    class view;
}

class view : public QDialog
{
    Q_OBJECT

public:
    explicit view(QWidget *parent = 0);
    ~view();
private slots:
    void setIntervalA();
    void setIntervalF();
    void setRM();
    void setAlgorithmsArg();
    void setReportDir();
    void start();
private:
    void createConnections();
    void saveSettings();
    void loadSettings();
    void isStarting();
    void isStopped();
    void setVisibleElements(bool isVisible);
private:
    QString reportDir;
    APFC apfc;
    Input in;
    SteeringMachine out;
    Ui::view *ui;
};

#endif // VIEW_H
