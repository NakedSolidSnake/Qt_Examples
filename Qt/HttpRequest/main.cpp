#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QNetworkAccessManager man;
//    QNetworkRequest req(QUrl("http://blog.qt.io/"));
    QNetworkRequest req(QUrl("http://www.gnu.org/licenses/lgpl-3.0.txt"));

    QString ua("HttpRequestDemo/0.1 (Linux64) Qt/5.7");

    req.setHeader(QNetworkRequest::UserAgentHeader, QVariant(ua));

    QNetworkReply *reply = man.get(req);

    QObject::connect(reply, &QNetworkReply::finished, [&](){
       QByteArray read = reply->readAll();

       QFile out ("lgpl-3.0.txt");
       out.open(QIODevice::WriteOnly | QIODevice::Text);
       out.write(read);
       out.close();

//       std::cout << "Got response:\n" << read.toStdString() << std::endl;
       reply->close();
       reply->deleteLater();
       a.quit();
    });

    return a.exec();
}
