#include "led.h"
#include <QString>
#include <QDebug>
#include <QTextStream>

Led* Led::instance = 0;
Led* Led::getInstance() 
{
	if(!instance) {
		instance = new Led();
		qDebug() << "getInstance(): First instance Led\n";
		return instance;
	}
	else {
	    qDebug() << "getInstance(): previous instance Led\n";
		return instance;
	}
}

Led::Led()
{
	variablesHandle  = Variables::getInstance();
	QFile file_export("/sys/class/gpio/export");
	if(file_export.open(QFile::WriteOnly |QFile::Text))
    {
		QTextStream out(&file_export); out << "18";
		file_export.close(); 
	}
	QFile file_direction("/sys/class/gpio/gpio18/direction");
	if(file_direction.open(QFile::WriteOnly |QFile::Text))
    {
		QTextStream out(&file_direction); out << "out";
		file_direction.close(); 
	}	
	QFile file_value("/sys/class/gpio/gpio18/value");
	if(file_value.open(QFile::WriteOnly |QFile::Text))
    {
		QTextStream out(&file_value); out << "0";
		file_value.close(); 
	}	
	Value = false ; 
}

void Led::SetValue(bool newValue )
{
	Value = newValue ; 
	//qDebug() << "led Value" << Value;
	QFile file_value("/sys/class/gpio/gpio18/value");
	if(file_value.open(QFile::WriteOnly |QFile::Text))
    {
		if (Value) {
			QTextStream out(&file_value); out << "1";
		} else {
			QTextStream out(&file_value); out << "0";
		}
		file_value.close(); 
	}	
}

bool Led::GetValue()
{
	return (Value) ; 
}


void Led::run()  
{
	while (1)
	{
		if ( variablesHandle->GetAlarmStatus() == eAlarmOn) 
		{
			SetValue(1);
			msleep (100);
			SetValue(0);
			msleep (5000);
		} 
		else if (( variablesHandle->GetAlarmStatus() == eAlarmDelayOn) || ( variablesHandle->GetAlarmStatus() == eAlarmDelayOff))
		{
			SetValue(1);
			msleep (500);
			SetValue(0);
			msleep (500);
		} else 
		{
			SetValue(0);
			msleep(100);
		}
	}
}
