#include "urllocation.h"
using namespace task4;

UrlLocation::UrlLocation(){}

UrlLocation::UrlLocation(QString filename, QString url, int line, int column):
    m_filename(filename), m_url(url), m_line(line), m_column(column){}

const QString& UrlLocation::get_filename() const
{
    return m_filename;
}

const QString& UrlLocation::get_url() const
{
    return m_url;
}

int UrlLocation::get_line() const { return m_line; }
int UrlLocation::get_column() const { return m_column; }

void UrlLocation::set_filename(const QString &newFilename)
{
    m_filename = newFilename;
}

void UrlLocation::set_line(int newLine)
{
    m_line = newLine;
}
