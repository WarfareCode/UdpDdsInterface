#include "mainwindow.h"
#include <QApplication>

#include "app.h"
#include <QDebug>
#include <QFile>
#include <QSettings>

//configuration file location
QString softPath = ".";

//read configuration file;
QString readConfig();

int main(int argc, char *argv[])
{
    readConfig();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

QString readConfig()
{
    qDebug() << "start to read configuration file !";

    QString strIniFile = QString("%0/config/system.ini").arg(softPath);
    QFile iniFile(strIniFile);
    QString logType, uuid;
    if (!iniFile.exists())
    {
        //软件首次运行
        QSettings *settings = new QSettings(strIniFile, QSettings::IniFormat);
        settings->beginGroup("System");
        settings->setValue("logType", "debug");
        settings->endGroup();
        delete settings;
    }

    QSettings settings(strIniFile, QSettings::IniFormat);
    settings.beginGroup("System");
    logType = settings.value("logType", "debug").toString();
    settings.endGroup();
    return uuid;
}
