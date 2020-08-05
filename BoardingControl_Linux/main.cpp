#include "logindialog.h"
#include "LogTrace/loghandler.h"
#include "homepage.h"
#include "settings.h"
#include "myeventfilter.h"

#include <QApplication>
#include <QDebug>
#include "ServerInterface/IDCardRead_Recog.h"
#include "ServerInterface/mqmsg_parse.h"
#include "ServerInterface/httpServer.h"
#include <QObject>
#include <QProcess>
#include <QTimer>



int main(int argc, char *argv[])
{
    int n;
    QString applicationPath;
    {
        qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

        Singleton<LogHandler>::getInstance().setSoftwareVersionInfo(2, 0, 0);

        QApplication app(argc, argv);
        //  安装log消息处理函数
        Singleton<LogHandler>::getInstance().installMessageHandler();
        //initialize local config file;
        LocalSettings::instance();
        //注册自定义类型到元类型
        regist_params();


        HomePage w;
        w.move(0, 0);
        w.showFullScreen();

        myEventFilter *p = new myEventFilter;
        app.installEventFilter(p);
        QObject::connect(p, &myEventFilter::mousePressNotify, &w, &HomePage::on_mousePressEventFilter);

        w.showSignInDlg();
        n = app.exec();

        delete  p;
        applicationPath = QApplication::applicationFilePath();
    }//加一个作用域，退出app.exec()时就释放HomePage
    if (773 == n){
        QThread::msleep(1000);
        qInfo()<<"[Auto Restart]";
        QProcess::startDetached(applicationPath);
    }
}
