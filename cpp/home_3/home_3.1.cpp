#include <iostream>
using namespace std;

int kvadr(int x)
{
    return x*x;
}

double kvadr(double x)
{
    return x*x;
}

int sum(int a, int b)
{
    return a+b;
}

int sum(int a, int b, int c)
{
    return a+b+c;
}

double multi(double a, double b=5)
{
    return a*b;
}

int main()
{
    cout<<kvadr(5)<<" "<<kvadr(5.1)<<" "<<sum(5, 9)<<" "<<sum(7, 7, 7)<<" "<<multi(10)<<endl;
    
    return 0;
}