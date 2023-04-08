#ifndef APP_H
#define APP_H

#include <QMainWindow>
#include "DiffEquations.h"
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class App; }
QT_END_NAMESPACE

class App : public QMainWindow
{
    Q_OBJECT

public:
    App(QWidget *parent = nullptr);
    ~App();

private slots:
    void on_send_clicked();

private:
    Ui::App *ui;
    DiffEquationsMethods *diff_;
    std::pair<std::vector<double>, std::vector<double>> dots_;
    QVector<double> x_,y_, acc_;
    void plot();


};
#endif // APP_H
