#include "sysinfowindowsimpl.h"

#include <windows.h>

SysINfoWindowsImpl::SysINfoWindowsImpl() : SysInfo(), mCpuLoadLastValues()
{

}

void SysINfoWindowsImpl::init()
{
    mCpuLoadLastValues = cpuRawData();
}

QVector<qulonglong> SysINfoWindowsImpl::cpuRawData()
{
    FILETIME idleTIme;
    FILETIME kernelTime;
    FILETIME userTime;

    GetSystemTimes(&idleTIme, &kernelTime, &userTime);

    QVector<qulonglong> rawData;

    rawData.append(convertFileTime(idleTIme));
    rawData.append(convertFileTime(kernelTime));
    rawData.append(convertFileTime(userTime));

    return rawData;
}

double SysINfoWindowsImpl::memoryUsed()
{
    MEMORYSTATUSEX memoryStatus;
    memoryStatus.dwLenght = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memoryStatus);
    qulonglong memoryPhysicalUsed = memoryStatus.ullTotalPhys - memoryStatus.ullAvailPhys;
    return (double)memoryPhysicalUsed / (double)memoryStatus.ullTotalPhys * 100.0;
}
