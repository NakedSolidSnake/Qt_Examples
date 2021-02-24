#include "randomvectorworker.h"
#include <QVector>
#include <QDateTime>
#include <QThread>
#include <QtDebug>

RandomVectorWorker::RandomVectorWorker(QObject *parent) : QObject(parent)
{

}

void RandomVectorWorker::inputHandler(const QString &in)
{
    qDebug() << "RandomVectorWorkers thread:" << QThread::currentThreadId();
    int size = in.toInt();

    QVector<int> vec;
    vec.resize(size);

    qsrand(QDateTime::currentMSecsSinceEpoch());

    for(int &num : vec)
    {
        num = qrand();
    }

    qDebug() << "Randomized";
}
