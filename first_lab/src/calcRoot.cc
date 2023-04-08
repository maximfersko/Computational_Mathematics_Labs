#include "calcRoot.h"

double calcRoot::func(double x) { return pow(x, 2) - 20 * sin(x) - 5; }

double calcRoot::func1(double x) { return 2 * x + 20 * cos(x); }

double calcRoot::func2(double x) { return 2 - 20 * sin(x); }

double calcRoot::toIter(double x) { return 20 * sin(x) + 5; }

void calcRoot::findRootDiv(double x1, double x2, double eps) {
    double x_next;
    count_ = 0;
    result_ = 0;
    while(abs(x2 - x1) > eps) {
        ++count_;
        x_next = (x1 + x2)/2;
        if(func(x_next) * func(x1) < 0) {
            x2 = x_next;
        } else {
            x1 = x_next;
        }
    }
    result_ = x_next;
}

void calcRoot::findRootIter(double x, double eps) {
   result_ = 0;
   count_ = 0;
   result_ = x - func(x) / f_prime(x);
    while (fabs(result_ - x) > eps) {
        ++count_;
        x = result_;
        result_ = x - func(x) / f_prime(x);
    }
}

void calcRoot::findRootNeuton(double x1, double x2, double eps) {;
    double x0 = (x1 + x2) / 2;
    result_ = x0;
    double h = func(result_) / f_prime(result_);
    while (fabs(h) >= eps && result_ >= x1 && result_ <= x2) {
        h = func(result_) / f_prime(result_);
        result_ -=  h;
    }
}