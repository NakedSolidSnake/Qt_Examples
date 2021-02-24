#ifndef INPUTWORKER_H
#define INPUTWORKER_H

#include <QObject>
#include <QTextStream>


class InputWorker : public QObject
{
    Q_OBJECT
public:
    explicit InputWorker(QObject *parent = 0);

signals:
    void inputAvailable(const QString&);

public slots:
    void startWork();

private:
    QTextStream is;
};

#endif // INPUTWORKER_H
