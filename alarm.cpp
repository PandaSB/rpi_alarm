#include "mainwindow.h"
#include "ibutton.h"
#include "variables.h"
#include "led.h"
#include "gsm.h"

#include <QApplication>
#include <QtWidgets>


int main(int argc, char *argv[ ])
{

    QApplication app(argc, argv);
    MainWindow *mainWindow = new MainWindow();
    Ibutton *ibutton = new Ibutton();
    Variables *variables = Variables::getInstance();
    Gsm *gsm = Gsm::getInstance();
    Led *led = Led::getInstance();

    QObject::connect(ibutton, &Ibutton::iButtonDetected , [=](QString ID) {
        qDebug() << "Callback ibutton" << ID;
        if (variables->CheckKeyId(ID))
        {
            if (variables->GetAlarmStatus() == eAlarmOff) mainWindow->AlarmOn(30) ; 
            else mainWindow->AlarmOff(0) ;
        }
    });
    led->start();
    ibutton->start();
    gsm->start();
    mainWindow->showFullScreen();
    return app.exec();
}