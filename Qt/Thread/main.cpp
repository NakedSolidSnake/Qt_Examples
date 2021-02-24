#include <QCoreApplication>
#include <QThread>
#include <QtDebug>
#include "inputworker.h"
#include "randomvectorworker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread thread1, thread2;
    thread1.start();
    thread2.start();

    InputWorker inputWorker;
    inputWorker.moveToThread(&thread1);

    RandomVectorWorker vecWorker;
    vecWorker.moveToThread(&thread2);

    QObject::connect(&inputWorker, &InputWorker::inputAvailable,
                     &vecWorker, &RandomVectorWorker::inputHandler);

    inputWorker.startWork();

    return a.exec();
}
