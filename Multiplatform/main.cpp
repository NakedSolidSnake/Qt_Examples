#include <QCoreApplication>
#include <QtDebug>
#include <QSysInfo>

void printHello()
{
#ifdef Q_OS_WIN
    qDebug() << "Hello Qt World on WIndows!";
    if(QSysInfo::windowsVersion() == QSysInfo::WV_XP)
    {
        qDebug() << "We're deprecating Windows XP support!";
    }
    else if(QSysInfo::windowsVersion() == QSysInfo::WV_10_0){
        qDebug() << "We're deprecating Windows XP support!";
    }
#elif defined(Q_OS_LINUX)
    qDebug() << "Hello Qt World on Linux!";
#else
    qDebug() << "We don't support this platform yet!";
#endif
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    (void)a;
    printHello();
    return 0;
}
