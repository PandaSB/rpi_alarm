#ifndef LED_H
#define LED_H
#include "variables.h"
#include <QThread>
#include <QFile>

class Led : public QThread
{
    Q_OBJECT
    void run() override ; 
public:
    Led();
    static Led *getInstance();  
    void SetValue(bool newValue);
    bool GetValue();

private:
    static Led *instance;
    bool Value = 0 ; 
    Variables *variablesHandle ;    


}; 
#endif 