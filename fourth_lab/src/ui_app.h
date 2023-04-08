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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
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
    QRadioButton *eulerMethod;
    QRadioButton *modEulerMethod;
    QRadioButton *rungeMethod;
    QRadioButton *AdamsMethod;
    QLabel *label;
    QSpinBox *point_x;
    QSpinBox *point_y;
    QLabel *k;
    QDoubleSpinBox *EPS;
    QLabel *label_4;
    QSpinBox *point_x_end;
    QLabel *label_2;
    QLabel *label_3;
    QDoubleSpinBox *step;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *App)
    {
        if (App->objectName().isEmpty())
            App->setObjectName(QString::fromUtf8("App"));
        App->resize(617, 359);
        centralwidget = new QWidget(App);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        send = new QPushButton(centralwidget);
        send->setObjectName(QString::fromUtf8("send"));
        send->setGeometry(QRect(30, 240, 121, 41));
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
        widget->setGeometry(QRect(190, 0, 411, 311));
        eulerMethod = new QRadioButton(centralwidget);
        eulerMethod->setObjectName(QString::fromUtf8("eulerMethod"));
        eulerMethod->setGeometry(QRect(130, 170, 51, 20));
        modEulerMethod = new QRadioButton(centralwidget);
        modEulerMethod->setObjectName(QString::fromUtf8("modEulerMethod"));
        modEulerMethod->setGeometry(QRect(10, 170, 111, 20));
        rungeMethod = new QRadioButton(centralwidget);
        rungeMethod->setObjectName(QString::fromUtf8("rungeMethod"));
        rungeMethod->setGeometry(QRect(100, 200, 89, 20));
        AdamsMethod = new QRadioButton(centralwidget);
        AdamsMethod->setObjectName(QString::fromUtf8("AdamsMethod"));
        AdamsMethod->setGeometry(QRect(10, 200, 81, 20));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 31, 20));
        point_x = new QSpinBox(centralwidget);
        point_x->setObjectName(QString::fromUtf8("point_x"));
        point_x->setGeometry(QRect(100, 20, 71, 21));
        point_y = new QSpinBox(centralwidget);
        point_y->setObjectName(QString::fromUtf8("point_y"));
        point_y->setGeometry(QRect(100, 50, 71, 22));
        k = new QLabel(centralwidget);
        k->setObjectName(QString::fromUtf8("k"));
        k->setGeometry(QRect(10, 50, 31, 21));
        EPS = new QDoubleSpinBox(centralwidget);
        EPS->setObjectName(QString::fromUtf8("EPS"));
        EPS->setGeometry(QRect(100, 140, 71, 21));
        EPS->setDecimals(7);
        EPS->setMaximum(10000.000000000000000);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 140, 31, 21));
        point_x_end = new QSpinBox(centralwidget);
        point_x_end->setObjectName(QString::fromUtf8("point_x_end"));
        point_x_end->setGeometry(QRect(100, 110, 71, 21));
        point_x_end->setMaximum(10000);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 110, 31, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 80, 41, 20));
        step = new QDoubleSpinBox(centralwidget);
        step->setObjectName(QString::fromUtf8("step"));
        step->setGeometry(QRect(100, 80, 71, 22));
        step->setDecimals(7);
        step->setMaximum(10000.000000000000000);
        App->setCentralWidget(centralwidget);
        menubar = new QMenuBar(App);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 617, 22));
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
        eulerMethod->setText(QCoreApplication::translate("App", "Euler", nullptr));
        modEulerMethod->setText(QCoreApplication::translate("App", "Modifaded Euler", nullptr));
        rungeMethod->setText(QCoreApplication::translate("App", "Runge-Kate", nullptr));
        AdamsMethod->setText(QCoreApplication::translate("App", "Adams 5-th", nullptr));
        label->setText(QCoreApplication::translate("App", "X0 = ", nullptr));
        k->setText(QCoreApplication::translate("App", "Y0 = ", nullptr));
        label_4->setText(QCoreApplication::translate("App", "EPS = ", nullptr));
        label_2->setText(QCoreApplication::translate("App", "Xn = ", nullptr));
        label_3->setText(QCoreApplication::translate("App", "Step  = ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class App: public Ui_App {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APP_H
