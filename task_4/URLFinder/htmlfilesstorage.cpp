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
    QStringList path_list = paths.split(u',');
    if(path_list.size() != 0)
    {
        foreach (const QString path, path_list)
        {
            QFile *file = new QFile(path);
            filepaths.push_back(file);
        }
    }
    else
    {
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
    // Вставить лог с уровнем INFO
    if(filepaths.size() == 0)
    {
        // Вставить лог с уровнем ERROR
        return false;
    }
    foreach (QFile *file, filepaths)
    {
        if(!file->exists())
        {
            // Вставить лог с уровнем ERROR
            return false;
        }
    }
    // Вставить лог с уровнем INFO
    return true;
}

void HtmlFilesStorage::find_urls()
{
    // Вставить лог с уровнем INFO
    // Регулярное выражение для
    QRegularExpression url_pattern(R"((http|ftp|gopher|news|telnet|file)\:(\/\/)www\.[a-z0-9]+\.[a-z]+\.ru)");
    // Открываем каждый файл и ищем в нем urls
    foreach (QFile *file, filepaths)
    {
        // Вставить лог с уровнем ERROR
        if(!file->open(QIODevice::ReadOnly | QIODevice::Text))
            throw "Не удалось открыть файл " + file->fileName() + " для чтения:";

        QTextStream in(file);

        for(int line = 1; !in.atEnd(); ++line)
        {
            QString l = in.readLine();
            QRegularExpressionMatchIterator match_it = url_pattern.globalMatch(l);
            while(match_it.hasNext())
            {
                QRegularExpressionMatch match = match_it.next();
                QString url = match.captured(1);
                int column = l.indexOf(url) + 1;
                UrlLocation location(file->fileName(), url, line, column);
                urls.push_back(location);
            }
        }

        file->close();
    }
    // Вставить лог с уровнем INFO
}


const QVector<UrlLocation>& HtmlFilesStorage::get_urls()
{
    return urls;
}
