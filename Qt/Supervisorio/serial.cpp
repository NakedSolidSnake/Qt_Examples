#include "serial.h"

Serial::Serial(QSerialPort *serialDev)
{
    this->serialDev = serialDev;
}

Serial::~Serial()
{

}

QStringList Serial::LoadSerialPorts()
{
    QStringList listSerialPorts;

    foreach (const QSerialPortInfo info, QSerialPortInfo::availablePorts()) {
        this->serialDev->setPort(info);

        if(this->serialDev->open(QIODevice::ReadWrite))
        {
            this->serialDev->close();
            listSerialPorts << info.portName();
        }
    }

    return listSerialPorts;
}

bool Serial::Connect(QString port, uint32_t baudRate)
{
    bool status = false;

    this->serialDev->setPortName(port);


    switch (baudRate) {
    case 2400:
        this->serialDev->setBaudRate(QSerialPort::Baud2400);
        break;

    case 4800:
        this->serialDev->setBaudRate(QSerialPort::Baud4800);
        break;

    case 9600:
        this->serialDev->setBaudRate(QSerialPort::Baud9600);
        break;

    case 19200:
        this->serialDev->setBaudRate(QSerialPort::Baud19200);
        break;

    case 115200:
        this->serialDev->setBaudRate(QSerialPort::Baud115200);
        break;
    default:
        //show message error
        return false;
        break;
    }

    this->serialDev->setFlowControl(QSerialPort::NoFlowControl);

    this->serialDev->setDataBits(QSerialPort::Data8);
    this->serialDev->setParity(QSerialPort::NoParity);
    this->serialDev->setStopBits(QSerialPort::OneStop);

    if(this->serialDev->open(QIODevice::ReadWrite))
    {
        status = true;
    }

    return status;
}

bool Serial::Desconnect(void)
{
    bool status = false;

    this->serialDev->clear();
    this->serialDev->close();

    if(this->serialDev->error() == 0 || !this->serialDev->isOpen())
    {
        status = true;
    }

    return status;
}

qint64 Serial::Write(const char *writeMessage)
{
    qint64 writeCount;

    writeCount = this->serialDev->write(cmd, qstrlen(writeMessage));

    return writeCount;
}

QString Serial::Read()
{
    QString messageRead;

    while (this->serialDev->waitForReadyRead(20)) {
        messageRead += this->serialDev->readAll();
    }

    return messageRead;
}

QString Serial::Read(int size)
{

    char messageRead[size];

    if(this->serialDev->canReadLine()){
        this->serialDev->read(messageRead, sizeof(messageRead));
    }

    return messageRead;
}
