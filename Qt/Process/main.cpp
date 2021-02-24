#include <QCoreApplication>
#include <QProcess>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "Main Process ID: " << a.applicationPid() << "\n";

    QStringList args;
    args << "/";

    QProcess process;

    process.setProgram("/usr/bin/find");
    process.setArguments(args);
    process.start();
    process.waitForStarted();

    process.write("HEllo World");

    process.waitForBytesWritten();
    process.closeWriteChannel();

    std::cout << "Process started: " << process.processId() << std::endl;
    process.waitForReadyRead();
    std::cout  << process.readAll().toBase64().toStdString() << std::endl;


    process.close();

    return 0;
}
