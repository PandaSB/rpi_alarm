#ifndef STATUS_H
#define STATUS_H

typedef enum {
    eAlarmOn,
    eAlarmOff,
    eAlarmDelay
} tAlarmStatus ;  

class Status
{
private:
    tAlarmStatus alarmStatus ;  
public:
    Status();
    ~Status();
    tAlarmStatus GetAlarmStatus();
    void SetAlarmStatus ( tAlarmStatus newstatus);
};


#endif 