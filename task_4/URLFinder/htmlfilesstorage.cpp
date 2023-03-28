#include "htmlfilesstorage.h"
#include <QStringList>
#include <QTextStream>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>

using namespace task4;

HtmlFilesStorage::HtmlFilesStorage(){}

HtmlFilesStorage::HtmlFilesStorage(QString paths)
{
    qDebug("Create HTML files storage");
    QStringList path_list = paths.split(u',');
    if(path_list.size() != 0)
    {
        foreach (QString path, path_list)
        {
            path = path.trimmed();
            QFile *file = new QFile(path);
            filepaths.push_back(file);
        }
    }
    else
    {
        qCritical("The file list is empty");
        throw "Названия файлов не были указаны!";
    }
}

HtmlFilesStorage::~HtmlFilesStorage()
{
    if(filepaths.size() != 0)
    {
        foreach (QFile *file, filepaths)
        {
            delete file;
        }
    }
}

bool HtmlFilesStorage::check_valid_paths()
{
    qDebug("Start to checking file paths for valid files");
    if(filepaths.size() == 0)
    {
        qCritical("Failed to check files - there are not paths");
        return false;
    }
    foreach (QFile *file, filepaths)
    {
        if(!file->exists())
        {
            qCritical("Failed to check files - some of files don't exist");
            return false;
        }
    }
    qDebug("End to checking file paths for valid files");
    return true;
}

void HtmlFilesStorage::find_urls()
{
    qDebug("Start to finding URLs from files");
    // Регулярное выражение для URL
    QRegularExpression url_pattern(R"((http|ftp|gopher|news|telnet|file)\:(\/\/)www\.[a-z0-9]+\.[a-z]+\.ru)");
    // Открываем каждый файл и ищем в нем urls
    foreach (QFile *file, filepaths)
    {
        if(!file->open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qCritical("Failed to open file for reading");
            throw "Не удалось открыть файл " + file->fileName() + " для чтения:";
        }

        QTextStream in(file);

        for(int line = 1; !in.atEnd(); ++line)
        {
            QString l = in.readLine();
            QRegularExpressionMatchIterator match_it = url_pattern.globalMatch(l);
            while(match_it.hasNext())
            {
                QRegularExpressionMatch match = match_it.next();
                QString url = match.captured(0);
                int column = l.indexOf(url) + 1;
                UrlLocation location(file->fileName(), url, line, column);
                urls.push_back(location);
            }
        }

        file->close();
    }
    qDebug("End to finding URLs from files");
}


const QVector<UrlLocation>& HtmlFilesStorage::get_urls()
{
    return urls;
}
