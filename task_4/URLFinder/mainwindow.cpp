#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      files("")
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_urlButton_clicked()
{
    qDebug("Click on url finding button");
    ui->urlListWidget->clear();
    try
    {
        task4::HtmlFilesStorage storage{files};
        if(!storage.check_valid_paths())
        {
            qCritical("Failed to check valid filepaths");
            ui->urlFindLabel->setText("Указан некорректный список файлов!");
            return;
        }

        storage.find_urls();

        QVector<task4::UrlLocation> result = storage.get_urls();
        if(result.size() == 0)
        {
            qDebug("There are not URLs in files");
            ui->urlFindLabel->setText("Строки запроса в указанных файлах не найдены");
            return;
        }

        ui->urlFindLabel->setText("Найденные строки запроса");

        foreach (const task4::UrlLocation& location, result)
        {
            // По хорошему, сделать свой виджет вывода
            QStringList info = {};
            info << "File: " << location.get_filename() << ", line: " << QString("%1").arg(location.get_line());
            info << ", column: " << QString("%1").arg(location.get_column());
            info << " -> URL: " << location.get_url();
            new QListWidgetItem(info.join(""), ui->urlListWidget);
        }

    } catch(const char *msg)
    {
        qDebug("Error");
        QMessageBox box;
        box.setText(msg);
        box.exec();
    }

}


void MainWindow::on_addFileButton_clicked()
{
    QStringList file = QFileDialog::getOpenFileNames(nullptr, "Open File", "", "*.html");
    if(file.isEmpty())
    {
       ui->urlFindLabel->setText("Указан некорректный список файлов!");
       return;
    }
    else
    {
        if(!files.isEmpty())
        {
            files += QString(",");
        }
        files += file;
        new QListWidgetItem(QString("File: %1").arg(file), ui->fileListWidget);
    }
}

