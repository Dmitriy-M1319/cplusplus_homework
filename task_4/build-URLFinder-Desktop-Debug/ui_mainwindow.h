/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *urlFindLabel;
    QPushButton *urlButton;
    QListWidget *urlListWidget;
    QPushButton *addFileButton;
    QLabel *label;
    QListWidget *fileListWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(962, 856);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        urlFindLabel = new QLabel(centralwidget);
        urlFindLabel->setObjectName(QString::fromUtf8("urlFindLabel"));
        urlFindLabel->setGeometry(QRect(240, 230, 511, 19));
        urlFindLabel->setAlignment(Qt::AlignCenter);
        urlButton = new QPushButton(centralwidget);
        urlButton->setObjectName(QString::fromUtf8("urlButton"));
        urlButton->setGeometry(QRect(710, 70, 161, 121));
        urlListWidget = new QListWidget(centralwidget);
        urlListWidget->setObjectName(QString::fromUtf8("urlListWidget"));
        urlListWidget->setGeometry(QRect(40, 300, 881, 501));
        addFileButton = new QPushButton(centralwidget);
        addFileButton->setObjectName(QString::fromUtf8("addFileButton"));
        addFileButton->setGeometry(QRect(70, 70, 171, 121));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(440, 40, 66, 19));
        fileListWidget = new QListWidget(centralwidget);
        fileListWidget->setObjectName(QString::fromUtf8("fileListWidget"));
        fileListWidget->setGeometry(QRect(350, 70, 256, 121));
        fileListWidget->setMovement(QListView::Free);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 962, 29));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "URL Finder", nullptr));
        urlFindLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
        urlButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270 \320\260\320\264\321\200\320\265\321\201\320\260", nullptr));
        addFileButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273\321\213:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
