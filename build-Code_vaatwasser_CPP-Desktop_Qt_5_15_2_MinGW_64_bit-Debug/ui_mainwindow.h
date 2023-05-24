/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *minutes60;
    QPushButton *minutes10;
    QPushButton *minutes5;
    QProgressBar *PowderLvl;
    QDial *ProgramDial;
    QDialogButtonBox *ok_cancel;
    QLabel *PowderLbl;
    QTextBrowser *Textfield;
    QMenuBar *menubar;
    QMenu *menuVaatwasser;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(548, 242);
        QPalette palette;
        QBrush brush(QColor(167, 167, 167, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush1(QColor(240, 240, 240, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        MainWindow->setPalette(palette);
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setKerning(true);
        MainWindow->setFont(font);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        minutes60 = new QPushButton(centralwidget);
        minutes60->setObjectName(QString::fromUtf8("minutes60"));
        minutes60->setGeometry(QRect(290, 170, 83, 29));
        minutes10 = new QPushButton(centralwidget);
        minutes10->setObjectName(QString::fromUtf8("minutes10"));
        minutes10->setGeometry(QRect(370, 170, 83, 29));
        minutes5 = new QPushButton(centralwidget);
        minutes5->setObjectName(QString::fromUtf8("minutes5"));
        minutes5->setGeometry(QRect(450, 170, 83, 29));
        PowderLvl = new QProgressBar(centralwidget);
        PowderLvl->setObjectName(QString::fromUtf8("PowderLvl"));
        PowderLvl->setGeometry(QRect(10, 130, 118, 23));
        PowderLvl->setAutoFillBackground(false);
        PowderLvl->setValue(24);
        PowderLvl->setTextVisible(true);
        ProgramDial = new QDial(centralwidget);
        ProgramDial->setObjectName(QString::fromUtf8("ProgramDial"));
        ProgramDial->setGeometry(QRect(340, 20, 131, 131));
        ok_cancel = new QDialogButtonBox(centralwidget);
        ok_cancel->setObjectName(QString::fromUtf8("ok_cancel"));
        ok_cancel->setGeometry(QRect(50, 170, 167, 29));
        ok_cancel->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        PowderLbl = new QLabel(centralwidget);
        PowderLbl->setObjectName(QString::fromUtf8("PowderLbl"));
        PowderLbl->setGeometry(QRect(200, 130, 63, 20));
        Textfield = new QTextBrowser(centralwidget);
        Textfield->setObjectName(QString::fromUtf8("Textfield"));
        Textfield->setGeometry(QRect(10, 10, 256, 111));
        MainWindow->setCentralWidget(centralwidget);
        minutes60->raise();
        minutes10->raise();
        minutes5->raise();
        ProgramDial->raise();
        ok_cancel->raise();
        PowderLbl->raise();
        Textfield->raise();
        PowderLvl->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 548, 17));
        menuVaatwasser = new QMenu(menubar);
        menuVaatwasser->setObjectName(QString::fromUtf8("menuVaatwasser"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuVaatwasser->menuAction());
        menuVaatwasser->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        minutes60->setToolTip(QCoreApplication::translate("MainWindow", "Add 60 minutes", nullptr));
#endif // QT_CONFIG(tooltip)
        minutes60->setText(QCoreApplication::translate("MainWindow", "60 minutes", nullptr));
#if QT_CONFIG(tooltip)
        minutes10->setToolTip(QCoreApplication::translate("MainWindow", "Add 10 minutes", nullptr));
#endif // QT_CONFIG(tooltip)
        minutes10->setText(QCoreApplication::translate("MainWindow", "10 minutes", nullptr));
#if QT_CONFIG(tooltip)
        minutes5->setToolTip(QCoreApplication::translate("MainWindow", "Add 5 minutes", nullptr));
#endif // QT_CONFIG(tooltip)
        minutes5->setText(QCoreApplication::translate("MainWindow", "5 minutes", nullptr));
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
