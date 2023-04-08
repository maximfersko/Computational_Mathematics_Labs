#include <iostream>
#include <math.h>
using namespace std;

double func(double x)
{
    double y = (1+x)/(pow((2+3*x),2));
    return y;
}
///Знаем, что результат вычисления интеграла в данном варианте = 0,1
double *MSP(double a, double b, int n)
{
    double *res = new double[2];
    double hMSP = (b-a)/(double)n;
    double sum = 0;
    double x = a;
    double t;
    for(int i=1;i<n;i++)
    {
        t=hMSP*func(x+hMSP/2);
        sum = sum + t;
        x = x+hMSP;
    }
    res[0]=sum;
    res[1]=hMSP;
    return res;
}

double *MLP(double a, double b, int n)
{
    double *res = new double[2];
    double hMLP = (b-a)/(double)n;
    double sum = 0;
    double x = a;
    double t;
    for(int i=0;i<n-1;i++)
    {
        t=hMLP*func(x);
        sum = sum + t;
        x = x+hMLP;
    }
    res[0]=sum;
    res[1]=hMLP;
    return res;
}
double *MT(double a, double b, int n)
{
    double *res = new double[2];
    double hMT = (b-a)/(double)n;
    double sum = 0;
    double x=a+hMT;
    double t;
    for(int i=1;i<n-1;i++)
    {
        t=hMT*func(x);
        sum = sum + t;
        x = x+hMT;
    }
    double result = (hMT/2)*func(a) + sum + (hMT/2)*func(b);
    res[0]=result;
    res[1]=hMT;
    return res;
}

double *solve(double a, double b, int nStart, double eps, double *(*func)(double, double, int))
{
    double integ;
    double n = nStart;
    double *res = new double[3];
    double delta = 1000;
    double F0 = func(a,b,n)[0];
    double h = func(a,b,n)[1];
    while(delta >= eps)
    {
        n*=1;
        integ = func(a,b,n)[0];
        h = func(a,b,n)[1];
        delta = integ - F0;
        F0=integ;
    }
    res[0]= F0;
    res[1]= n;
    res[2]= h;
    return res;
}

int main()
{
    setlocale(LC_ALL,"Russian");
    double a=1;
    double b=3;
    double eps=0.1;
    /**********Метод средних прямоугольников**************/
    cout<<"Метод средних прямоугольников" << endl;
    double *res1 = solve(a,b,2,eps,MSP);
    double *res11 = solve(a,b,2,0.1*eps,MSP);
    cout << "Численного значение интеграла при eps=0.1 - " << res1[0] << "; количество итераций n=" << res1[1] << "; шаг h=" << res1[2] << "." << endl;
    cout << "Численного значение интеграла при eps=0.01 - " << res11[0] << "; количество итераций n=" << res11[1] << "; шаг h=" << res11[2] << ".\n" << endl;
    /*****************************************************/

    /**********Метод левых прямоугольников****************/
    cout<<"Метод левых прямоугольников" << endl;
    double *res2 = solve(a,b,2,eps,MLP);
    double *res22 = solve(a,b,2,0.1*eps,MLP);
    cout << "Численного значение интеграла при eps=0.1 - " << res2[0] << "; количество итераций n=" << res2[1] << "; шаг h=" << res2[2] << "." << endl;
    cout << "Численного значение интеграла при eps=0.01 - " << res22[0] << "; количество итераций n=" << res22[1] << "; шаг h=" << res22[2] << ".\n" << endl;
    /*****************************************************/

    /**********Метод трапеций*****************************/
    cout<<"Метод трапеций" << endl;
    double *res3 = solve(a,b,2,eps,MT);
    double *res33 = solve(a,b,2,0.1*eps,MT);
    cout << "Численного значение интеграла при eps=0.1 - " << res3[0] << "; количество итераций n=" << res3[1] << "; шаг h=" << res3[2] << "." << endl;
    cout << "Численного значение интеграла при eps=0.01 - " << res33[0] << "; количество итераций n=" << res33[1] << "; шаг h=" << res33[2] << ".\n" << endl;
    /*****************************************************/

    return 0;
}
