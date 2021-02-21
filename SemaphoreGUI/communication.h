#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class Communication : public QObject
{
    Q_OBJECT
public:
    explicit Communication(QObject *parent = nullptr);
    ~Communication();

   Q_INVOKABLE void openSerialPort();
   Q_INVOKABLE void closeSerialPort();
   Q_INVOKABLE void writeSerialData(QByteArray &data);

signals:
    void getData();

public slots:
    QByteArray readSerialData();
    void dataReady();


private:
    QSerialPort *m_serial;

};

#endif // COMMUNICATION_H
