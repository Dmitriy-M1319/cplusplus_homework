#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QDateTime>
#include <QTextStream>
#include <QString>
#include <QFile>

/**
* @brief myLogMessageHandler Собственный обработчик сообщений, который позволяет вести лог в файл
* @param type Уровень лога
* @param msg Сообщение от логгера
*/
void myLogMessageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg)
{
    QFile log_file("applog.log");
    if(!log_file.open(QIODeviceBase::Append | QIODeviceBase::Text))
    {
        return;
    }

    QString log_curr_time = "[" +
              QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss.zzz") + "]";

    QTextStream log_stream(&log_file);
    switch(type){
        case QtDebugMsg:
            log_stream << QString("%1 Info - %2").arg(log_curr_time).arg(msg);
            break;
        case QtWarningMsg:
            log_stream << QString("%1 Warning - %2").arg(log_curr_time).arg(msg);
            break;
        case QtCriticalMsg:
            log_stream << QString("%1 Critical - %2").arg(log_curr_time).arg(msg);
            break;
        case QtFatalMsg:
            log_stream << QString("%1 Fatal - %2").arg(log_curr_time).arg(msg);
            abort();
    }
    log_stream.flush();
    log_file.flush();
    log_file.close();
}

int main(int argc, char *argv[])
{
    qInstallMessageHandler(myLogMessageHandler);
    QApplication a(argc, argv);
    qDebug() << "Start Qt Application";
    MainWindow w;
    w.show();
    qDebug("Close Qt Application");
    return a.exec();
}
