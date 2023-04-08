#include "DiffEquations.h"

DiffEquationsMethods::DiffEquationsMethods(double x0, double y0, double xEnd,
                                           double step, double eps)
    : x0_(x0), y0_(y0), xEnd_(xEnd), step_(step), eps_(eps) {}

std::pair<std::vector<double>, std::vector<double>> DiffEquationsMethods::Methods(std::string method) {
     std::pair<std::vector<double>, std::vector<double>> result;
    if (method == "Euler") {
        EulerMethod();
        result.first = x_;
        result.second = y_;
    } else if (method == "RungeKuttaMerson") {
        RungeKuttaMersonMethod();
        result.first = x_;
        result.second = y_;
    } else if (method == "modifededEuler") {
        modifededEulerMethod();
        result.first = x_;
        result.second = y_;
    } else if (method == "Adams") {
        AdamsMethod();
        result.first = x_;
        result.second = y_;
    } else {
        std::cout << "Wrong method name" << std::endl;
    }
    std::cout << "x: " << x_.size() << std::endl;
    std::cout << "x: " << result.first.size() << std::endl;
    std::cout << "y: " << y_.size() << std::endl;
    std::cout << "y: " << result.second.size() << std::endl;
    return result;
}

double DiffEquationsMethods::fXY(double x, double y) { return 3 - y - x; }

double DiffEquationsMethods::AccFunc(double x) { return 4 - x - 4 * exp(-x); }

void DiffEquationsMethods::clear() {
    x_.clear();
    y_.clear();
}

void DiffEquationsMethods::EulerMethod() {
    clear();
    int nEuler = (xEnd_ - x0_) / step_;
    x_.push_back(x0_);
    y_.push_back(y0_);
    // int i = 1;
    for (int i = 1; i <= nEuler; ++i) {
        x_.push_back(x_[i - 1] + step_);
        y_.push_back(y_[i - 1] + step_ * fXY(x_[i - 1], y_[i - 1]));
    }
    /*
    --i;
    std::cout << "Значение х: " << x_[i] << std::endl;
    std::cout << "Значение у: " << y_[i]
         << " Точное значение=" << AccFunc(xEnd_) << "\n"
         << std::endl;
         */
}

void DiffEquationsMethods::RungeKuttaMersonMethod() {
    clear();
       /*****************Метод Рунге-Кутта Мерсона*******************/

   std::cout << "Метод Рунгe-Кутта Мерсона" << std::endl;
    x_.push_back(x0_);
    y_.push_back(y0_);
    int n = 0;
    double k1,k2,k3,k4,k5,delta,temp_y;
    while(x_[n] < xEnd_)
    {
        //Этот if нужен для того, чтобы последний шаг был ровно до xn, а не превышал ее.
        if(x_[n]+step_ > xEnd_)
        {
            step_ = xEnd_-x_[n];
        }
        k1 = step_*fXY(x_[n],y_[n]);
        k2 = step_*fXY(x_[n]+step_/3,y_[n]+k1/3);
        k3 = step_*fXY(x_[n]+step_/3,y_[n]+(k1/6+k2/6));
        k4 = step_*fXY(x_[n]+step_/2,y_[n]+k1/8+(3*k3)/8);
        k5 = step_*fXY(x_[n]+step_,y_[n]+k1/2-(3*k3)/2+2*k4);
        delta = (-2*k1-9*k3-8*k4+k5)*(step_/30);
        if(abs(delta) > eps_)
        {
            step_ = step_/2;
            k1 = step_*fXY(x_[n],y_[n]);
            k2 = step_*fXY(x_[n]+step_/3,y_[n]+k1/3);
            k3 = step_*fXY(x_[n]+step_/3,y_[n]+(k1/6+k2/6));
            k4 = step_*fXY(x_[n]+step_/2,y_[n]+k1/8+(3*k3)/8);
            k5 = step_*fXY(x_[n]+step_,y_[n]+k1/2-(3*k3)/2+2*k4);
            temp_y = y_[n]+(k1+4*k4+k5)/6;
            y_.push_back(temp_y);
            x_.push_back(x_[n] + step_);
            ++n;
            continue;
        }
        if(abs(delta) < eps_/30)
        {
           step_= step_*2;
        }

        temp_y = y_[n]+(k1+4*k4+k5)/6;
        y_.push_back(temp_y);
        x_.push_back(x_[n] + step_);
        ++n;
    }
    std::cout << "Значение х: " << x_[n] << std::endl;
    std::cout << "Значение у: " << y_[n] << " Точное значение=" <<AccFunc(xEnd_)<< "\n" << std::endl;
    std::cout << " " << std::endl;

    /**********************************************************************/

    // std::cout << "Значение х: " << x_[i] << std::endl;
    // std::cout << "Значение у: " << y_[i]
    //           << " Точное значение=" << AccFunc(xEnd_) << "\n"
    //           << std::endl;
    // std::cout << " " << std::endl;
}

void DiffEquationsMethods::modifededEulerMethod() {
    clear();
    //step_ = 0.01;
    int nModEuler = (xEnd_ - x0_) / step_;
    x_.push_back(x0_);
    y_.push_back(y0_);
    //int i = 1;
    for (int i = 1; i <= nModEuler; ++i) {
        x_.push_back(x_[i - 1] + step_);
        y_.push_back(y_[i - 1] + step_ * fXY(x_[i - 1], y_[i - 1]));
        y_[i] = y_[i - 1] +
                step_ * (fXY(x_[i - 1], y_[i - 1]) + fXY(x_[i], y_[i])) / 2;
    }
    //--i;
    /*
    std::cout << "Значение х: " << x_[i] << std::endl;
    std::cout << "Значение у: " << y_[i]
         << " Точное значение=" << AccFunc(xEnd_) << "\n"
         << std::endl;
    */
}

void DiffEquationsMethods::AdamsMethod() {
    clear();
    //step_ = 0.01;
    int nAdams = (xEnd_ - x0_) / step_;
    std::array<double, 4> firstX;
    std::array<double, 4> firstY;
    std::vector<double> funcValue;
    x_.push_back(x0_);
    y_.push_back(y0_);
    funcValue.push_back(fXY(x_[0], y_[0]));
    for (int i = 1; i <= 4; ++i) {
        x_.push_back(x_[i - 1] + step_);
        y_.push_back(y_[i - 1] + step_ * fXY(x_[i - 1], y_[i - 1]));
        funcValue.push_back(fXY(x_[i], y_[i]));
    }
    std::vector<double> xAdams;
    std::vector<double> yAdams;
    for (int i = 0; i < 4; ++i) {
        xAdams.push_back(x_[i]);
        yAdams.push_back(y_[i]);
    }
    //int i = 5;
    for (int i = 5; i <= nAdams; ++i) {
        x_.push_back(x_[i - 1] + step_);
        y_.push_back(y_[i - 1] +
                     (step_ / 720) *
                         (1901 * funcValue[i - 1] - 2774 * funcValue[i - 2] +
                          2616 * funcValue[i - 3] - 1274 * funcValue[i - 4] +
                          251 * funcValue[i - 5]));
        funcValue.push_back(fXY(x_[i], y_[i]));
    }
    /*
    --i;
    std::cout << "Значение х: " << x_[i] << std::endl;
    std::cout << "Значение у: " << y_[i] << " Точное значение=" << AccFunc(xEnd_)
         << "\n"
         << std::endl;
    */
}


std::vector<double> DiffEquationsMethods::Accuracy() {
    std::vector<double> result;
    for (int x = 0; x <= x_.size(); ++x) {
        result.push_back(AccFunc(x));
    }
    return result;
}
