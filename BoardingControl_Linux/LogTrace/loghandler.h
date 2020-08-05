#ifndef LOGHANDLER_H
#define LOGHANDLER_H

#include "LogTrace/singleton.h"

struct LogHandlerPrivate;

class LogHandler {
    SINGLETON(LogHandler) // 使用单例模式
public:
    void installMessageHandler(); // 给 Qt 安装消息处理函数

    void release(); // 释放资源

    //软件设置版本号
    //major_ver:主版本号; secondary_ver:次版本号; corrective_ver:修正版本号
    //V1.2.3.4_1586013058: major_ver=1, secondary_ver=2, corrective_ver=3, build=4, buildTimeStamp=1586013058;
    void setSoftwareVersionInfo(int major_ver, int secondary_ver, int corrective_ver);

private:
    LogHandlerPrivate *d;
};

#endif // LOGHANDLER_H
