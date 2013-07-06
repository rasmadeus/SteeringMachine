#ifndef VIEW_H
#define VIEW_H

#include <QDialog>

class Output;
class APFC;
class Input;
class APFCThread;

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
    void threadWasStarted();
    void threadWasFinished();
    void createNewContour(int i);
private:
    void initContour();
    void createConnections();
    void saveSettings();
    void loadSettings();
    void setElementsEnabled(bool is, const QString& text);
private:
    APFC* apfc;
    Input* in;
    Output* out;
    APFCThread* thread;
    Ui::view *ui;
};

#endif // VIEW_H
