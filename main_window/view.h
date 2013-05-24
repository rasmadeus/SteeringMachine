#ifndef VIEW_H
#define VIEW_H

#include <QDialog>

class Output;
class APFC;
class Input;

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
    void setReportDir();
    void start();
    void createNewContour(int i);
private:
    void initContour();
    void createConnections();
    void saveSettings();
    void loadSettings();
    void isStarting();
    void isStopped();
    void setVisibleElements(bool isVisible);
private:
    QString reportDir;
    APFC* apfc;
    Input* in;
    Output* out;
    Ui::view *ui;
};

#endif // VIEW_H
