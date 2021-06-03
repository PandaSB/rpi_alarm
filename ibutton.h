#ifndef IBUTTON_H
#define IBUTTON_H

#include <QThread>

class Ibutton : public QThread
{
    Q_OBJECT
    void run() override ; 
signals:
    void iButtonDetected(const QString &s);
};


#endif 