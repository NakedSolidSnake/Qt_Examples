#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <QObject>
#include <QDebug>
#include <QString>

class Debugger
{
public:
    Debugger();

    static void Debug_Print(QString msg)
    {
        qDebug() << msg;
    }
};

#endif // DEBUGGER_H
