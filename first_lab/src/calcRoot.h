#include <iostream>
#include <cmath>

class calcRoot
{

public:
    calcRoot() {}
    void findRootDiv(double x1, double x2, double eps);
    void findRootIter(double x, double eps);
    void findRootNeuton(double x1, double x2, double eps);
    double getResult() { return result_; }
    double getCountIteration() { return count_; }
    double f_prime(double x) { return 2 * x - 20 * cos(x); }
    ~calcRoot() {}

private:
    double result_ = 0;
    int count_ = 0;

    double func(double x);
    double func1(double x);
    double func2(double x);
    double toIter(double x);

};



