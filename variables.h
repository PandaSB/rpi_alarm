#ifndef VARIABLES_H
#define VARIABLES_H

#include <QString>

typedef enum {
    eAlarmOn,
    eAlarmOff,
    eAlarmDelayOn,
    eAlarmDelayOff
} tAlarmStatus ;  

class Variables
{
private:
    static Variables *instance;
    tAlarmStatus alarmStatus ;
    QString KeyIds ;
    QString CodeAlarm;
public:
    Variables();
    static Variables *getInstance();

    tAlarmStatus GetAlarmStatus();
    void SetAlarmStatus ( tAlarmStatus newVariables);
    bool CheckKeyId (QString id); 
    bool CheckCodeAlarm ( QString code ); 

    
};


#endif 