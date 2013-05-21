#include <QtGui/QApplication>
#include "main_window/view.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication SteeringMachine(argc, argv);

    QApplication::setOrganizationName("Fakel");
    QApplication::setApplicationName("Contour calculater");
    QApplication::setApplicationVersion("1.0");

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("cp1251"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("cp1251"));

        view mainWindow;
        mainWindow.show();

    return SteeringMachine.exec();
}
