#ifndef URLLOCATION_H
#define URLLOCATION_H

#include <QString>


namespace task4
{
class UrlLocation
{
private:
    QString filename;
    QString url;
    int line;
    int column;

public:
    UrlLocation();
    UrlLocation(QString filename, QString url, int line, int column);
    const QString& get_filename() const;
    const QString& get_url() const;
    int get_line() const;
    int get_column() const;
};
}

#endif // URLLOCATION_H
