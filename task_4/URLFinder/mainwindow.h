#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "htmlfilesstorage.h"
#include "urllocation.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_urlButton_clicked();

    void on_addFileButton_clicked();

private:
    Ui::MainWindow *ui;
    QString files;
};
#endif // MAINWINDOW_H
