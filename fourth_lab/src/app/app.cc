#include "app.h"
#include "ui_app.h"

App::App(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::App)
{
    ui->setupUi(this);

}

App::~App()
{
    delete ui;
}


void App::on_send_clicked()
{
    diff_ = new DiffEquationsMethods(ui->point_x->value(), ui->point_y->value(),
                              ui->point_x_end->value(), ui->step->value(),
                              ui->EPS->value());
    if (ui->eulerMethod->isChecked()) {
        dots_ = diff_->Methods("Euler");
    } else if (ui->modEulerMethod->isChecked()) {
        dots_ = diff_->Methods("modifededEuler");
    } else if (ui->AdamsMethod->isChecked()) {
        dots_ = diff_->Methods("Adams");
    } else if (ui->rungeMethod->isChecked()) {
        dots_ = diff_->Methods("RungeKuttaMerson");
    }
    plot();
}


void App::plot() {
    ui->widget->xAxis->setRange(-1 * dots_.second.front(),dots_.second.front());
    ui->widget->yAxis->setRange(-1 * dots_.second.back(),dots_.second.back());

   if (dots_.first.size() == dots_.second.size()) {
       x_ = QVector<double>(dots_.first.begin(), dots_.first.end());
       y_ = QVector<double>(dots_.second.begin(), dots_.second.end());

    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x_, y_);
    ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->widget->graph(0)->setScatterStyle(
        QCPScatterStyle(QCPScatterStyle::ssCircle, 1.0));
    ui->widget->replot();
     ui->widget->setInteractions(QCP::iRangeDrag |
     QCP::iRangeZoom |
                                 QCP::iSelectPlottables);
   }
}
