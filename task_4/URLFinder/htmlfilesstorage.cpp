#include "htmlfilesstorage.h"
#include <QStringList>
#include <QTextStream>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>

using namespace task4;

HtmlFilesStorage::HtmlFilesStorage(){}

HtmlFilesStorage::HtmlFilesStorage(QString paths): m_pattern(R"((http|ftp|gopher|news|telnet|file)\:(\/\/)www\.[a-z0-9]+\.[a-z0-9]+\.ru)")
{
    qDebug("Create HTML files storage");
    QStringList path_list = paths.split(u',');
    if(path_list.size() != 0)
    {
        foreach (QString path, path_list)
        {
            path = path.trimmed();
            QFile *file = new QFile(path);
            m_filepaths.push_back(file);
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
    if(m_filepaths.size() != 0)
    {
        foreach (QFile *file, m_filepaths)
        {
            delete file;
        }
    }
}

bool HtmlFilesStorage::check_valid_paths()
{
    qDebug("Start to checking file paths for valid files");
    if(m_filepaths.size() == 0)
    {
        qCritical("Failed to check files - there are not paths");
        return false;
    }
    foreach (QFile *file, m_filepaths)
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

void find_url_in_line(QString &line, const QRegularExpression &pattern, QVector<UrlLocation> &urls)
{
    QRegularExpressionMatchIterator match_it = pattern.globalMatch(line);
    while(match_it.hasNext())
    {
        QRegularExpressionMatch match = match_it.next();
        QString url = match.captured(0);
        int column = line.indexOf(url) + 1;
        UrlLocation location("", url, 0, column);
        urls.push_back(location);
    }
}


void read_lines(QTextStream &stream, const QRegularExpression &pattern, QVector<UrlLocation> &urls)
{
    for(int line = 1; !stream.atEnd(); ++line)
    {
        auto l = stream.readLine();
        find_url_in_line(l, pattern, urls);
        for(UrlLocation &loc: urls)
            loc.set_line(line);
    }
}


// Сделать перегрузку на строку, стрим или файл
void HtmlFilesStorage::find_urls()
{
    qDebug("Start to finding URLs from files");
    // Открываем каждый файл и ищем в нем urls
    foreach (QFile *file, m_filepaths)
    {
        if(!file->open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qCritical("Failed to open file for reading");
            throw "Не удалось открыть файл " + file->fileName() + " для чтения:";
        }
        QTextStream in(file);
        read_lines(in, m_pattern, m_urls);
        for(UrlLocation &loc: m_urls)
            loc.set_filename(file->fileName());

        file->close();
    }
    qDebug("End to finding URLs from files");
}


const QVector<UrlLocation>& HtmlFilesStorage::get_urls()
{
    return m_urls;
}
