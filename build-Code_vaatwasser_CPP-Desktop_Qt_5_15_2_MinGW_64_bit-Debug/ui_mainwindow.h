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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QProgressBar *lblPowderLvl;
    QPlainTextEdit *txtInfo;
    QGroupBox *gbHidden;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnStateSwGlass;
    QPushButton *btnStateSwEco;
    QPushButton *btnStateSwCeramic;
    QGroupBox *gbTime;
    QHBoxLayout *horizontalLayout_2;
    QLCDNumber *txtTime;
    QPushButton *btnMinutes60;
    QPushButton *btnMinutes10;
    QPushButton *btnMinutes5;
    QGroupBox *gbSelCtrl;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnOkProg;
    QPushButton *btnReturnProg;
    QGroupBox *gbProgram;
    QVBoxLayout *verticalLayout;
    QComboBox *cmbProgramSel;
    QMenuBar *menubar;
    QMenu *menuVaatwasser;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(538, 238);
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
        lblPowderLvl = new QProgressBar(centralwidget);
        lblPowderLvl->setObjectName(QString::fromUtf8("lblPowderLvl"));
        lblPowderLvl->setGeometry(QRect(380, 10, 118, 23));
        lblPowderLvl->setAutoFillBackground(false);
        lblPowderLvl->setValue(100);
        lblPowderLvl->setTextVisible(true);
        txtInfo = new QPlainTextEdit(centralwidget);
        txtInfo->setObjectName(QString::fromUtf8("txtInfo"));
        txtInfo->setGeometry(QRect(10, 10, 341, 141));
        gbHidden = new QGroupBox(centralwidget);
        gbHidden->setObjectName(QString::fromUtf8("gbHidden"));
        gbHidden->setGeometry(QRect(100, 30, 98, 95));
        verticalLayout_2 = new QVBoxLayout(gbHidden);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        btnStateSwGlass = new QPushButton(gbHidden);
        btnStateSwGlass->setObjectName(QString::fromUtf8("btnStateSwGlass"));

        verticalLayout_2->addWidget(btnStateSwGlass);

        btnStateSwEco = new QPushButton(gbHidden);
        btnStateSwEco->setObjectName(QString::fromUtf8("btnStateSwEco"));

        verticalLayout_2->addWidget(btnStateSwEco);

        btnStateSwCeramic = new QPushButton(gbHidden);
        btnStateSwCeramic->setObjectName(QString::fromUtf8("btnStateSwCeramic"));

        verticalLayout_2->addWidget(btnStateSwCeramic);

        gbTime = new QGroupBox(centralwidget);
        gbTime->setObjectName(QString::fromUtf8("gbTime"));
        gbTime->setGeometry(QRect(260, 160, 261, 51));
        horizontalLayout_2 = new QHBoxLayout(gbTime);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        txtTime = new QLCDNumber(gbTime);
        txtTime->setObjectName(QString::fromUtf8("txtTime"));

        horizontalLayout_2->addWidget(txtTime);

        btnMinutes60 = new QPushButton(gbTime);
        btnMinutes60->setObjectName(QString::fromUtf8("btnMinutes60"));

        horizontalLayout_2->addWidget(btnMinutes60);

        btnMinutes10 = new QPushButton(gbTime);
        btnMinutes10->setObjectName(QString::fromUtf8("btnMinutes10"));

        horizontalLayout_2->addWidget(btnMinutes10);

        btnMinutes5 = new QPushButton(gbTime);
        btnMinutes5->setObjectName(QString::fromUtf8("btnMinutes5"));

        horizontalLayout_2->addWidget(btnMinutes5);

        gbSelCtrl = new QGroupBox(centralwidget);
        gbSelCtrl->setObjectName(QString::fromUtf8("gbSelCtrl"));
        gbSelCtrl->setGeometry(QRect(10, 160, 182, 51));
        horizontalLayout = new QHBoxLayout(gbSelCtrl);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnOkProg = new QPushButton(gbSelCtrl);
        btnOkProg->setObjectName(QString::fromUtf8("btnOkProg"));

        horizontalLayout->addWidget(btnOkProg);

        btnReturnProg = new QPushButton(gbSelCtrl);
        btnReturnProg->setObjectName(QString::fromUtf8("btnReturnProg"));

        horizontalLayout->addWidget(btnReturnProg);

        gbProgram = new QGroupBox(centralwidget);
        gbProgram->setObjectName(QString::fromUtf8("gbProgram"));
        gbProgram->setGeometry(QRect(370, 50, 131, 61));
        verticalLayout = new QVBoxLayout(gbProgram);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        cmbProgramSel = new QComboBox(gbProgram);
        cmbProgramSel->addItem(QString());
        cmbProgramSel->addItem(QString());
        cmbProgramSel->addItem(QString());
        cmbProgramSel->addItem(QString());
        cmbProgramSel->setObjectName(QString::fromUtf8("cmbProgramSel"));

        verticalLayout->addWidget(cmbProgramSel);

        MainWindow->setCentralWidget(centralwidget);
        txtInfo->raise();
        lblPowderLvl->raise();
        gbHidden->raise();
        gbTime->raise();
        gbSelCtrl->raise();
        gbProgram->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 538, 17));
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
        lblPowderLvl->setToolTip(QCoreApplication::translate("MainWindow", "Powder level;", nullptr));
#endif // QT_CONFIG(tooltip)
        gbHidden->setTitle(QCoreApplication::translate("MainWindow", "Hidden", nullptr));
        btnStateSwGlass->setText(QCoreApplication::translate("MainWindow", "stateSwGlass", nullptr));
        btnStateSwEco->setText(QCoreApplication::translate("MainWindow", "stateSwEco", nullptr));
        btnStateSwCeramic->setText(QCoreApplication::translate("MainWindow", "stateSwCeramic", nullptr));
        gbTime->setTitle(QCoreApplication::translate("MainWindow", "Time", nullptr));
#if QT_CONFIG(tooltip)
        btnMinutes60->setToolTip(QCoreApplication::translate("MainWindow", "Add 60 minutes", nullptr));
#endif // QT_CONFIG(tooltip)
        btnMinutes60->setText(QCoreApplication::translate("MainWindow", "60 minutes", nullptr));
#if QT_CONFIG(tooltip)
        btnMinutes10->setToolTip(QCoreApplication::translate("MainWindow", "Add 10 minutes", nullptr));
#endif // QT_CONFIG(tooltip)
        btnMinutes10->setText(QCoreApplication::translate("MainWindow", "10 minutes", nullptr));
#if QT_CONFIG(tooltip)
        btnMinutes5->setToolTip(QCoreApplication::translate("MainWindow", "Add 5 minutes", nullptr));
#endif // QT_CONFIG(tooltip)
        btnMinutes5->setText(QCoreApplication::translate("MainWindow", "5 minutes", nullptr));
        gbSelCtrl->setTitle(QCoreApplication::translate("MainWindow", "Selection controls", nullptr));
        btnOkProg->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        btnReturnProg->setText(QCoreApplication::translate("MainWindow", "Return", nullptr));
        gbProgram->setTitle(QCoreApplication::translate("MainWindow", "Program", nullptr));
        cmbProgramSel->setItemText(0, QCoreApplication::translate("MainWindow", "Select program", nullptr));
        cmbProgramSel->setItemText(1, QCoreApplication::translate("MainWindow", "Glass", nullptr));
        cmbProgramSel->setItemText(2, QCoreApplication::translate("MainWindow", "Eco", nullptr));
        cmbProgramSel->setItemText(3, QCoreApplication::translate("MainWindow", "Ceramic", nullptr));

        cmbProgramSel->setCurrentText(QString());
        cmbProgramSel->setPlaceholderText(QCoreApplication::translate("MainWindow", "Select program", nullptr));
        menuVaatwasser->setTitle(QCoreApplication::translate("MainWindow", "Vaatwasser", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
