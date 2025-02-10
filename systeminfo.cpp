#include "systeminfo.h"
#include <QFile>
#include <QTextStream>
#include <QtCore/qthread.h>

SystemInfo::SystemInfo(QObject *parent) : QObject(parent) {}

QString SystemInfo::cpuArchitecture() const {
    return QSysInfo::currentCpuArchitecture();
}

int SystemInfo::cpuCores() const {
    return QThread :: idealThreadCount();  // Returns available cores
}

QString SystemInfo::totalRAM() const {
#ifdef Q_OS_LINUX
    QFile file("/proc/meminfo");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString line = in.readLine();  // Read first line (MemTotal)
        file.close();
        return QString::number(line.split(QRegExp("\\s+"))[1].toLongLong() / 1024) + " MB";
    }
    return "N/A";
#elif defined(Q_OS_WIN)
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);
    GlobalMemoryStatusEx(&statex);
    return QString::number(statex.ullTotalPhys / (1024 * 1024)) + " MB";
#elif defined(Q_OS_MAC)
    int mib[] = {CTL_HW, HW_MEMSIZE};
    int64_t mem;
    size_t len = sizeof(mem);
    sysctl(mib, 2, &mem, &len, nullptr, 0);
    return QString::number(mem / (1024 * 1024)) + " MB";
#else
    return "Unsupported OS";
#endif
}
