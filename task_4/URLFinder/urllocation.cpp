#include "urllocation.h"
using namespace task4;

UrlLocation::UrlLocation(){}

UrlLocation::UrlLocation(QString filename, QString url, int line, int column):
    filename(filename), url(url), line(line), column(column){}

const QString& UrlLocation::get_filename() const
{
    return filename;
}

const QString& UrlLocation::get_url() const
{
    return url;
}

int UrlLocation::get_line() const { return line; }
int UrlLocation::get_column() const { return column; }
