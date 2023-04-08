#ifndef APP_H
#define APP_H

#include <QMainWindow>
#include "Interpolation.h"
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
    void plot(std::vector<double> x, std::vector<double> y);


};
#endif // APP_H
