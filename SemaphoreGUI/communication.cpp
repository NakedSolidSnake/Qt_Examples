#include "communication.h"
#include <QDebug>

Communication::Communication(QObject *parent) : QObject(parent)
{
    m_serial = new QSerialPort(this);
    m_serial->setPortName("/dev/ttyACM0");
    m_serial->setDataBits(QSerialPort::DataBits::Data8);
    m_serial->setParity(QSerialPort::Parity::NoParity);
    m_serial->setStopBits(QSerialPort::StopBits::OneStop);
    m_serial->setBaudRate(QSerialPort::Baud9600);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);
//    connect(m_serial, &QSerialPort::readyRead, this, &Communication::readSerialData);
    connect(m_serial, &QSerialPort::readyRead, this, &Communication::dataReady);
}

Communication::~Communication()
{
    delete m_serial;
}

void Communication::openSerialPort()
{
    if(m_serial->isOpen())
        m_serial->close();

    m_serial->open(QIODevice::ReadWrite);
    m_serial->flush();
    qDebug() << "Serial opened.";
}

void Communication::closeSerialPort()
{
    if(m_serial->isOpen()){
        m_serial->flush();
        m_serial->clear();
        m_serial->close();
        qDebug() << "Serial closed.";
    }
}

void Communication::writeSerialData(QByteArray &data)
{
    m_serial->write(data);
}

QByteArray Communication::readSerialData()
{
    QByteArray data;
    while(m_serial->waitForReadyRead(5)){
        data.append(m_serial->readAll());
    }
    m_serial->flush();
    return data;
}

void Communication::dataReady()
{
    emit getData();
}
