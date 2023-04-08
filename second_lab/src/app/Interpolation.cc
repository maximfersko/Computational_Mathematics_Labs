#include "Interpolation.h"

//Интерполяционные многочлены Ньютона и Лагранжа

/****************Интерполяционный многочлен Лагранжа*******************/
//Вычисление многочлена Лагранжа в точке x
double Lagrange(double x, std::vector<double> yEx, int n, double a, double b)
{
    double h = (b-a)/n;
    std::vector<double> xCur;
    double s=0;//Значение многочлена в точке x
    double p1,p2;
    for(int i=0; i<=n; i++)
    {
        xCur.push_back(a+i*h);
    }
    for(int k = 0; k<=n;k++)
    {
        p1=1;
        p2=1;
        for(int m = 0; m<=n; m++)
        {
            if(k != m)
            {
                p1=p1*(x-xCur[m]);
                p2=p2*(xCur[k]-xCur[m]);
            }
        }
        s+=yEx[k]*(p1/p2);
    }
    return s;
}
///Составление нужного количества точек x для интерполированной функции
std::vector<double> xPoints(double a, double b, int n)
{
    std::vector<double> x;
    x.push_back(a);
    double h = (b-a)/n;
    for(int i=1; i <=n; i++)
    {
        x.push_back(x[i-1]+h);
    }
    return x;
}
///Вычисление точек у интерполированной функции Лагранжа
std::vector<double> yPointsL(double a, double b, int n, int nL, std::vector<double> yEx)
{
    std::vector<double> y;
    std::vector<double> x = xPoints(a,b,n);
    for(int i=0; i < x.size(); i++)
    {
        y.push_back(Lagrange(x[i],yEx,nL,a,b));
    }
    return y;
}
/**************************************************/

/***********Итерполяционный многочлен Ньютона**********/
///Вычисление разделенных разностей
std::vector<std::vector<double>> razdRazn(int n, std::vector<double> yEx)
{
    //Cоздаем массив разделенных разностей
    std::vector<std::vector<double>> v;
    v.resize(n);
    for(int i =0; i < v.size(); i++)
    {
        v[i].resize(n);
    }
    //Заполняем
    for(int i = 0; i <n; i ++)
    {
        v[i][0] = yEx[i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            v[j][i] = v[j+1][i-1]-v[j][i-1];
        }
    }
    return v;
}
///Вычисление многочлена Ньютона в конкретной точке x
double Nuton(double x, double a, double b, int n, std::vector<double> yEx)
{
    std::vector<std::vector<double>> f = razdRazn(5,yEx);
    double h = (b-a)/n;
    double s = f[0][0];
    double st = 1;
    double fac = 1;
    std::vector<double> xCur;
    for(int i=0; i<=n; i++)
    {
        xCur.push_back(a+i*h);
    }
    for(int i=0; i<=n-1; i++)
    {
        st = st*(x-xCur[i]);
        fac = fac*(i+1)*h;
        s=s + f[0][i+1]*st/fac;
    }
    return s;
}
///Вычисление точек у интерполированной функции Ньютона
std::vector<double> yPointsN(double a, double b, int n, int nN, std::vector<double> yEx)
{
    std::vector<double> y;
    std::vector<double> x = xPoints(a,b,n);
    for(int i=0; i < x.size(); i++)
    {
        y.push_back(Nuton(x[i],a,b,nN,yEx));
    }
    return y;
}
/*********************************************************/

/*

int main()
{
    double a = 1;
    double b = 5;
    int nL = 4;
    int n = 500;
    vector<double> yEx = {4,2,8,1,-1};
    vector<double> xPts = xPoints(a,b,n);///Точки х для обоих многочленов
    vector<double> yL = yPointsL(a,b,n,nL,yEx);///Точки у для многочлена лагранжа
    vector<double> yN = yPointsN(a,b,n,nL,yEx);///Точки у для многочлена ньютона
    cout << Nuton(2.6,a,b,nL,yEx) << endl;
    cout << Lagrange(2.6,yEx,nL,a,b) << endl;
    return 0;
}

*/
