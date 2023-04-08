#include <math.h>

#include <array>
#include <iostream>
#include <vector>

class DiffEquationsMethods {
   public:
     std::pair<std::vector<double>, std::vector<double>> Methods(std::string method);
    DiffEquationsMethods(double x0, double y0, double xEnd, double step,
                         double eps);
    std::vector<double> getX() { return x_; }
    std::vector<double> getY() { return y_; }
    std::vector<double> Accuracy();
    double AccFunc(double x);
    std::pair<std::vector<double>, std::vector<double>> graphBuilder();

   private:
    double x0_;
    double y0_;
    double xEnd_;
    double step_;
    double eps_;
    std::vector<double> x_;
    std::vector<double> y_;

    double fXY(double x, double y);
    void EulerMethod();
    void RungeKuttaMersonMethod();
    void modifededEulerMethod();
    void AdamsMethod();
    void clear();

};  // class DiffEquationsMethods
