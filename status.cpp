#include "status.h"

Status::Status()
{
    alarmStatus = eAlarmOff ;
}

Status::~Status()
{
}

tAlarmStatus Status::GetAlarmStatus()
{
    return (alarmStatus) ;
}


void Status::SetAlarmStatus ( tAlarmStatus newstatus)
{
    alarmStatus = newstatus ; 
}