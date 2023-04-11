#ifndef HTMLFILESSTORAGE_H
#define HTMLFILESSTORAGE_H

#include <QVector>
#include <QFile>
#include <QString>
#include <QRegularExpression>

#include "urllocation.h"

namespace task4
{
    class HtmlFilesStorage
    {

    public:
        HtmlFilesStorage();
        HtmlFilesStorage(QString paths);
       ~HtmlFilesStorage();

        /// Проверяет на корректность пути до файлов (не до каталогов и т.д.)
        bool check_valid_paths();

        /// Ищет во всех файлах url формата протокол://www.tratata.ppp.ru и заполняет urls
        void find_urls();

        /// Получить все найденные строки запроса
        const QVector<UrlLocation>& get_urls();
    private:
        /// Хранилище путей до файлов в виде объектов QFile
        QVector<QFile*> m_filepaths;
        /// Хранилище всех найденных путей
        QVector<UrlLocation> m_urls;
        /// Паттерн для поиска URL
        QRegularExpression m_pattern;
    };
}

#endif // HTMLFILESSTORAGE_H
