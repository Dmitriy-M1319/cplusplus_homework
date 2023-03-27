#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QMessageBox>
#include <QLabel>
#include <QStackedLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->urlsScrollArea->widget()->setLayout(new QStackedLayout());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_urlButton_clicked()
{
    // Вставить лог с уровнем INFO
    try
    {
        QString paths = ui->filesLineInput->text();
        task4::HtmlFilesStorage storage{paths};
        if(!storage.check_valid_paths())
        {
            // Вставить лог с уровнем ERROR
            ui->urlFindLabel->setText("Указан некорректный список файлов!");
            return;
        }

        storage.find_urls();

        QVector<task4::UrlLocation> result = storage.get_urls();
        if(result.size() == 0)
        {
            // Вставить лог с уровнем INFO
            ui->urlFindLabel->setText("Строки запроса в указанных файлах не найдены");
            return;
        }

        foreach (const task4::UrlLocation& location, result)
        {
            // По хорошему, сделать свой виджет вывода
            QLabel *child_label = new QLabel();
            QStringList info = {};
            info << "File: " << location.get_filename() << ", line: " << QString("%1").arg(location.get_line());
            info << ", column: " << QString("%1").arg(location.get_column());
            info << "\nURL: " << location.get_url();
            child_label->setText(info.join(""));
            ui->urlsScrollArea->widget()->layout()->addWidget(child_label);
        }


    } catch(const char *msg)
    {
        // Вставить лог с уровнем ERROR
        QMessageBox box;
        box.setText(msg);
        box.exec();
    }

}

