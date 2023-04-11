#ifndef URLLOCATION_H
#define URLLOCATION_H

#include <QString>


namespace task4
{
class UrlLocation
{
public:
    UrlLocation();
    UrlLocation(QString filename, QString url, int line, int column);
    const QString& get_filename() const;
    const QString& get_url() const;
    int get_line() const;
    int get_column() const;
    void set_filename(const QString &newFilename);
    void set_line(int newLine);

private:
    QString m_filename;
    QString m_url;
    int m_line;
    int m_column;
};
}

#endif // URLLOCATION_H
