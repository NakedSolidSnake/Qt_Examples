#include <QCoreApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QtDebug>

#define NO_TIMEOUT -1

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTcpServer server;

    if(!server.listen(QHostAddress::LocalHost, 54321))
    {
        qDebug() << "Failed to listen at localhost:54321";
        return 1;
    }

    server.waitForNewConnection(NO_TIMEOUT);
    QTcpSocket *con = server.nextPendingConnection();
    QByteArray toWrite("Hello from server");

    con->write(toWrite);
    con->waitForBytesWritten();
    con->waitForReadyRead();

    QByteArray readData = con->readAll();
    qDebug () << "Server reads" << readData;
    con->close();
    con->deleteLater();

    server.close();

    qDebug() << "Bye";


    return a.exec();
}
