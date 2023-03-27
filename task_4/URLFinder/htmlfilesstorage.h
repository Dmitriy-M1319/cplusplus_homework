#ifndef HTMLFILESSTORAGE_H
#define HTMLFILESSTORAGE_H

#include <QVector>
#include <QFile>
#include <QString>

#include "urllocation.h"

namespace task4
{
    class HtmlFilesStorage
    {
    private:
        /// Хранилище путей до файлов в виде объектов QFile
        QVector<QFile*> filepaths;
        /// Хранилище всех найденных путей
        QVector<UrlLocation> urls;
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
    };
}

#endif // HTMLFILESSTORAGE_H
