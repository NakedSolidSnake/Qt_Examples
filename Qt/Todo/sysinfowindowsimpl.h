#ifndef SYSINFOWINDOWSIMPL_H
#define SYSINFOWINDOWSIMPL_H

#include <QtGlobal>
#include <QVector>

#include "sysinfo.h"

typedef struct _FILETIME FILETIME;

class SysINfoWindowsImpl : public SysInfo
{
public:
    SysINfoWindowsImpl();



    // SysInfo interface
public:
    void init() override;
    double cpuLoadAverage() override;
    double memoryUsed() override;

private:
    QVector<qulonglong> cpuRawData();
    qulonglong convertFileTime(const FILETIME& filetime) const;

private:
    QVector<qulonglong> mCpuLoadLastValues;
};

#endif // SYSINFOWINDOWSIMPL_H
