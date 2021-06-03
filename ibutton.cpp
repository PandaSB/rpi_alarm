#include "ibutton.h"
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTest>

void Ibutton::run()  
{
    QString szPresent = "/sys/devices/w1_bus_master1/w1_master_slaves";
    QString szDelete  = "/sys/devices/w1_bus_master1/w1_master_remove"; 
    QString szID =""; 
    while (1)
    {
        QFile file(szPresent);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            szID  = file.readLine();
            if (szID.compare ("not found.\n",Qt::CaseSensitive) != 0 )
            {
                qDebug() << "ID : " << szID;
                emit iButtonDetected(szID);
                QFile fileDelete(szDelete);
                if (fileDelete.open(QIODevice::WriteOnly))
                {
                    QTextStream out(&fileDelete); out << szID;
                    qDebug() << "Delete ID : " << szID;
                    fileDelete.close();
                }
                else
                {
                    qDebug() << "Error opening " << szDelete;
                }
            }
            file.close() ; 
        } else
        {
            qDebug() << "Error opening " << szPresent;
        }
    }
}
