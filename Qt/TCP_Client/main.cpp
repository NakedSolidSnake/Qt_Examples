#include <QCoreApplication>
#include <QTcpSocket>
#include <QHostAddress>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTcpSocket client;

    client.connectToHost(QHostAddress::LocalHost, 54321);
    client.waitForConnected();

    if(client.state() != QTcpSocket::ConnectedState)
    {
        qDebug () << "Failed to connect to localhost:54321";
        return 1;
    }

    client.waitForReadyRead();
    QByteArray readData =  client.readAll();
    qDebug() << "Client reads "  << readData;

    QByteArray toWrite("Hello from client");
    client.write(toWrite);
    client.waitForBytesWritten();

    qDebug() << "Bye";


    return a.exec();
}
