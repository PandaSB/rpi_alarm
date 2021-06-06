#include "gsm.h"
#include <QDebug>

#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()

Gsm* Gsm::instance = 0;
Gsm* Gsm::getInstance() 
{
	if(!instance) {
		instance = new Gsm();
		qDebug() << "getInstance(): First instance Gsm\n";
		return instance;
	}
	else {
	    qDebug() << "getInstance(): previous instance Gsm\n";
		return instance;
	}
}

Gsm::Gsm()
{

    struct termios tty;
    serial_port = open("/dev/ttyUSB0", O_RDWR);
    if (serial_port < 0) 
    {
        qDebug() << "Error " << errno << " from open: " << strerror(errno);
        return ; 
    }
    if(tcgetattr(serial_port, &tty) != 0) 
    {
        qDebug() << "Error " << errno << " from tcgetattr: " << strerror(errno);
    }
    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CSIZE; tty.c_cflag |= CS8;
    tty.c_cflag &= ~CRTSCTS;
    tty.c_cflag |= CREAD | CLOCAL;
    tty.c_lflag &= ~ICANON;
    tty.c_lflag &= ~ECHO;
    tty.c_lflag &= ~ISIG;
    tty.c_iflag &= ~(IXON | IXOFF | IXANY);
    tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL);
    tty.c_oflag &= ~OPOST;
    tty.c_oflag &= ~ONLCR;
    tty.c_cc[VTIME] = 10;
    tty.c_cc[VMIN] = 0;
    cfsetispeed(&tty, B115200);
    cfsetospeed(&tty, B115200);

    if (tcsetattr(serial_port, TCSANOW, &tty) != 0) 
    {
        qDebug() << "Error " << errno << " from tcsetattr: " << strerror(errno);
    }

}


void Gsm::run()  
{
    char read_buf [256];
    int num_bytes  = 0;
    memset(&read_buf, '\0', sizeof(read_buf));
    while (1)
    {
        mtx.lock();
        num_bytes = read(serial_port, &read_buf, sizeof(read_buf));
        //qDebug() << num_bytes ; 
        if (num_bytes < 0) {
            qDebug() << "Error reading: " << errno << " from read: " << strerror(errno);
        } 
        if (num_bytes > 0) 
        {
            read_buf[num_bytes] = '\0' ; 
            Buffer.append (read_buf) ;                 
        }
        mtx.unlock();
    }
}

void Gsm::SendCmd ( QString cmd)
{
    mtx.lock();
    QByteArray ba = cmd.toLocal8Bit();
    const char *c_str = ba.data();
    write(serial_port, c_str, cmd.length());
    mtx.unlock();
}