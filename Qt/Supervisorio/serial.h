#ifndef SERIAL_H
#define SERIAL_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class Serial
{
public:
    Serial(QSerialPort *serialDev);
    ~Serial();

    QStringList LoadSerialPorts();

    bool Connect(QString port, uint32_t baudRate);
    bool Desconnect(void);

    qint64 Write(const char writeMessage);
    QString Read();
    QString Read(int size);

protected:
    QSerialPort *serialDev;

};

#endif // SERIAL_H
