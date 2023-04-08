/********************************************************************************
** Form generated from reading UI file 'app.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APP_H
#define UI_APP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_App
{
public:
    QWidget *centralwidget;
    QPushButton *send;
    QCustomPlot *widget;
    QRadioButton *Lagrange;
    QRadioButton *Newton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *App)
    {
        if (App->objectName().isEmpty())
            App->setObjectName(QString::fromUtf8("App"));
        App->resize(477, 447);
        centralwidget = new QWidget(App);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        send = new QPushButton(centralwidget);
        send->setObjectName(QString::fromUtf8("send"));
        send->setGeometry(QRect(160, 360, 131, 41));
        send->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 149, 58);\n"
"\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
" \n"
"}\n"
"QPushButton:pressed {\n"
"    background-color:  rgb(255, 143, 50);\n"
"}"));
        widget = new QCustomPlot(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 461, 311));
        Lagrange = new QRadioButton(centralwidget);
        Lagrange->setObjectName(QString::fromUtf8("Lagrange"));
        Lagrange->setGeometry(QRect(110, 320, 89, 20));
        Newton = new QRadioButton(centralwidget);
        Newton->setObjectName(QString::fromUtf8("Newton"));
        Newton->setGeometry(QRect(250, 320, 89, 20));
        App->setCentralWidget(centralwidget);
        menubar = new QMenuBar(App);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 477, 22));
        App->setMenuBar(menubar);
        statusbar = new QStatusBar(App);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        App->setStatusBar(statusbar);

        retranslateUi(App);

        QMetaObject::connectSlotsByName(App);
    } // setupUi

    void retranslateUi(QMainWindow *App)
    {
        App->setWindowTitle(QCoreApplication::translate("App", "App", nullptr));
        send->setText(QCoreApplication::translate("App", "Calculate", nullptr));
        Lagrange->setText(QCoreApplication::translate("App", "Lagrange", nullptr));
        Newton->setText(QCoreApplication::translate("App", "Newton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class App: public Ui_App {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APP_H
