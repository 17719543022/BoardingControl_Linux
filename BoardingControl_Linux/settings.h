﻿#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>

class LocalSettings : public QSettings
{
public:
      ~LocalSettings();

      static LocalSettings* instance();

private:
      explicit LocalSettings(const QString &fileName, Format format, QObject *parent = nullptr);
};

inline LocalSettings* LocalSettings::instance(){
    static LocalSettings inst("./config/settings.ini", QSettings::IniFormat);
    return &inst;
}

#define MSEC_EVENTLOOP_TIMEOUT 2000

#endif // SETTINGSINFO_H
