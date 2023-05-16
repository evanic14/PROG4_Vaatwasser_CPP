/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QProgressBar *PowderLvl;
    QDial *ProgramDial;
    QDialogButtonBox *buttonBox;
    QLabel *PowderLbl;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QMenu *menuVaatwasser;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(550, 254);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(290, 170, 83, 29));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(370, 170, 83, 29));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(450, 170, 83, 29));
        PowderLvl = new QProgressBar(centralwidget);
        PowderLvl->setObjectName(QString::fromUtf8("PowderLvl"));
        PowderLvl->setGeometry(QRect(580, 290, 118, 23));
        PowderLvl->setAutoFillBackground(false);
        PowderLvl->setValue(24);
        PowderLvl->setTextVisible(true);
        ProgramDial = new QDial(centralwidget);
        ProgramDial->setObjectName(QString::fromUtf8("ProgramDial"));
        ProgramDial->setGeometry(QRect(350, 20, 111, 121));
        buttonBox = new QDialogButtonBox(centralwidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 170, 167, 29));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        PowderLbl = new QLabel(centralwidget);
        PowderLbl->setObjectName(QString::fromUtf8("PowderLbl"));
        PowderLbl->setGeometry(QRect(610, 330, 63, 20));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 256, 111));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 550, 25));
        menuVaatwasser = new QMenu(menubar);
        menuVaatwasser->setObjectName(QString::fromUtf8("menuVaatwasser"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuVaatwasser->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_5->setToolTip(QCoreApplication::translate("MainWindow", "Add 60 minutes", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "60 minutes", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_6->setToolTip(QCoreApplication::translate("MainWindow", "Add 10 minutes", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "10 minutes", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_7->setToolTip(QCoreApplication::translate("MainWindow", "Add 5 minutes", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "5 minutes", nullptr));
#if QT_CONFIG(tooltip)
        PowderLvl->setToolTip(QCoreApplication::translate("MainWindow", "Powder level;", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        ProgramDial->setToolTip(QCoreApplication::translate("MainWindow", "Program selection dial", nullptr));
#endif // QT_CONFIG(tooltip)
        PowderLbl->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        menuVaatwasser->setTitle(QCoreApplication::translate("MainWindow", "Vaatwasser", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
