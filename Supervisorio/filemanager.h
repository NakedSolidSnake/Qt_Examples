#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <QFile>
#include <QString>

class FileManager
{
public:
    FileManager();
    FileManager(QString filename);

    size_t Write(const QString writeText);
    size_t Read(QString& readText);

    enum ErrorFileMessages {
      FILE_OK,
      FILE_CANNOT_OPEN
    };


private:
    QFile *file;




    //error messages
    QString errorMessagesDebug[10] = {
      "File open OK",
      "File Cannot Open"
    };



};

#endif // FILEMANAGER_H
