#ifndef SYSTEMINFO_H
#define SYSTEMINFO_H

#include <QObject>
#include <QSysInfo>

#ifdef Q_OS_WIN
#include <windows.h>
#elif defined(Q_OS_MAC)
#include <sys/types.h>
#include <sys/sysctl.h>
#endif

class SystemInfo : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString cpuArchitecture READ cpuArchitecture NOTIFY infoChanged)
    Q_PROPERTY(int cpuCores READ cpuCores NOTIFY infoChanged)
    Q_PROPERTY(QString totalRAM READ totalRAM NOTIFY infoChanged)

public:
    explicit SystemInfo(QObject *parent = nullptr);

    QString cpuArchitecture() const;
    int cpuCores() const;
    QString totalRAM() const;

signals:
    void infoChanged();
};

#endif // SYSTEMINFO_H
