#include <iostream>
#include <vector>


double Lagrange(double x, std::vector<double> yEx, int n, double a, double b);
std::vector<double> xPoints(double a, double b, int n);
std::vector<double> yPointsL(double a, double b, int n, int nL, std::vector<double> yEx);
std::vector<std::vector<double>> razdRazn(int n, std::vector<double> yEx);
double Nuton(double x, double a, double b, int n, std::vector<double> yEx);
std::vector<double> yPointsN(double a, double b, int n, int nN, std::vector<double> yEx);
