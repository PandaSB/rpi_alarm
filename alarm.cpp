#include "mainwindow.h"
#include "ibutton.h"
#include "status.h"

#include <QApplication>
#include <QtWidgets>


int main(int argc, char *argv[ ])
{

    QApplication app(argc, argv);
    MainWindow mainWindow;
    Ibutton *ibutton = new Ibutton();
    Status *status = new Status();

    QObject::connect(ibutton, &Ibutton::iButtonDetected , [=](QString ID) {
        qDebug() << "Callback ibutton" << ID;
    });
    ibutton->start();
    mainWindow.showFullScreen();
    return app.exec();
}