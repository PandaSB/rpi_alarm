#ifndef GSM_H
#define GSM_H

#include <QThread>
#include <mutex>  

class Gsm : public QThread
{
    Q_OBJECT
    void run() override ; 
public:
    Gsm();
    static Gsm *getInstance();    

private:
    static Gsm *instance;
    int serial_port;
    std::mutex mtx;
    QString Buffer = "";

};

#endif 