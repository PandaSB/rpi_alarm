#include "variables.h"
#include <QDebug>



Variables* Variables::instance = 0;
Variables* Variables::getInstance() 
{
	if(!instance) {
		instance = new Variables();
		qDebug() << "getInstance(): First instance\n";
		return instance;
	}
	else {
	    qDebug() << "getInstance(): previous instance\n";
		return instance;
	}
}

Variables::Variables()
{
    alarmStatus = eAlarmOff ;
	KeyIds =  "01-000001676e36 01-000003303aec 01-0000055c4a1a";
	CodeAlarm =  "1234" ; 
}

tAlarmStatus Variables::GetAlarmStatus()
{
    return (alarmStatus) ;
}


void Variables::SetAlarmStatus ( tAlarmStatus newAlarmStatus)
{
    alarmStatus = newAlarmStatus ; 
}

bool Variables::CheckKeyId ( QString id )
{
	if ((KeyIds.indexOf(id) != -1) && (id.length() == 15)) return true ; 
	else return (false) ; 
}

bool Variables::CheckCodeAlarm ( QString code )
{
	if (CodeAlarm.compare(code,Qt::CaseSensitive) == 0) return true ; 
	else return (false) ; 
}