#ifndef IBUTTON_H
#define IBUTTON_H


/*
echo "dtoverlay=w1-gpio,gpiopin=4" >> /boot/config.txt 
ech "options wire timeout=1 slave_ttl=3" > /etc/modprobe.d/w1.conf
sudo chmod a+w /sys/devices/w1_bus_master1/w1_master_remove
*/

#include <QThread>

class Ibutton : public QThread
{
    Q_OBJECT
    void run() override ; 
signals:
    void iButtonDetected(const QString &s);
};


#endif 