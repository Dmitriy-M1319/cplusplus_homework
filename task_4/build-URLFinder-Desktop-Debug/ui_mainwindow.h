/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QLineEdit *filesLineInput;
    QLabel *label;
    QLabel *urlFindLabel;
    QPushButton *urlButton;
    QListWidget *urlListWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(962, 856);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        filesLineInput = new QLineEdit(centralwidget);
        filesLineInput->setObjectName("filesLineInput");
        filesLineInput->setGeometry(QRect(40, 80, 881, 36));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 50, 681, 19));
        urlFindLabel = new QLabel(centralwidget);
        urlFindLabel->setObjectName("urlFindLabel");
        urlFindLabel->setGeometry(QRect(230, 180, 511, 19));
        urlFindLabel->setAlignment(Qt::AlignCenter);
        urlButton = new QPushButton(centralwidget);
        urlButton->setObjectName("urlButton");
        urlButton->setGeometry(QRect(330, 130, 301, 36));
        urlListWidget = new QListWidget(centralwidget);
        urlListWidget->setObjectName("urlListWidget");
        urlListWidget->setGeometry(QRect(40, 220, 881, 581));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 962, 29));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "URL Finder", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\276\320\273\320\275\321\213\320\265 \320\270\320\273\320\270 \320\276\321\202\320\275\320\276\321\201\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\265 \320\277\321\203\321\202\320\270 \320\264\320\276 \321\204\320\260\320\271\320\273\320\276\320\262 \321\204\320\276\321\200\320\274\320\260\321\202\320\260 HTML \321\207\320\265\321\200\320\265\320\267 \320\267\320\260\320\277\321\217\321\202\321\203\321\216 \320\262 \320\277\320\276\320\273\320\265 \320\275\320\270\320\266\320\265:</p></body></html>", nullptr));
        urlFindLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
        urlButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270 \320\260\320\264\321\200\320\265\321\201\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
