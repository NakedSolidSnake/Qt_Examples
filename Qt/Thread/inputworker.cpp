#include "inputworker.h"
#include <QThread>
#include <QtDebug>

InputWorker::InputWorker(QObject *parent) : QObject(parent),
    is(stdin)
{

}

void InputWorker::startWork()
{
    qDebug() << "Input worker thread:" << QThread::currentThread();

    do
    {
        qDebug() << "Input the size of vector";
        QString input = is.readLine();
        emit inputAvailable(input);
    }while (true);
}
