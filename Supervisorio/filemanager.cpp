#include "filemanager.h"
#include "debugger.h"
#include <QTextStream>

FileManager::FileManager()
{
    file =  new QFile();
}

FileManager::FileManager(QString filename)
{
    //Create a handle
    file =  new QFile(filename);
}

size_t FileManager::Write(const QString writeText)
{
    size_t writeCount = 0;

//    open file and test
    if(!file->open(QIODevice::WriteOnly)){
        Debugger::Debug_Print(errorMessagesDebug[FILE_CANNOT_OPEN]);
        return 0;
    }

    Debugger::Debug_Print(errorMessagesDebug[FILE_OK]);

    writeCount = writeText.size();

    //write file
    QTextStream outStream(file);
    outStream << writeText;
    file->flush();
    file->close();
    return writeCount;
}

size_t FileManager::Read(QString& readText)
{
    (void)readText;
    size_t readCount = 0;
    //    open file and test
    if(!file->open(QIODevice::ReadOnly)){
        Debugger::Debug_Print(errorMessagesDebug[FILE_CANNOT_OPEN]);
        return 0;
    }

     Debugger::Debug_Print(errorMessagesDebug[FILE_OK]);

    //read file
     QTextStream inStream(file);
     readText = inStream.readAll();
     readCount = readText.size();
     file->flush();
     file->close();

     return readCount;
}




