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
    double a = 1;
    double b = 5;
    int nL = 4;
    int n = 500;
    std::vector<double> yEx{4,2,8,1,-1};
    std::vector<double> xPts = xPoints(a,b,n);///Т
    std::vector<double> yL = yPointsL(a,b,n,nL,yEx);
    std::vector<double> yN = yPointsN(a,b,n,nL,yEx);
    //cout << Nuton(2.6,a,b,nL,yEx) << endl;
    //cout << Lagrange(2.6,yEx,nL,a,b) << endl;
    if (ui->Lagrange->isChecked()) {
        plot(xPts, yL);
    } else if (ui->Newton->isChecked()) {
        plot(xPts, yN);
    }

}


void App::plot(std::vector<double> x, std::vector<double> y) {
    ui->widget->xAxis->setRange(-1 * y.front(),y.front());
    ui->widget->yAxis->setRange(-1 * y.back(),y.back());


      QVector<double> X(x.begin(), x.end());
      QVector<double> Y(y.begin(), y.end());

    ui->widget->addGraph();
   ui->widget->graph(0)->setData(X, Y);

    ui->widget->graph(0)->setScatterStyle(
        QCPScatterStyle(QCPScatterStyle::ssCircle, 4.0));
    ui->widget->replot();
     ui->widget->setInteractions(QCP::iRangeDrag |
     QCP::iRangeZoom |
                                 QCP::iSelectPlottables);
}
