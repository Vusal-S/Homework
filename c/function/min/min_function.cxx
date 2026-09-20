#include <stdio.h>
#include <math.h>

double f(double x) {return x / (x * x + 1);}

double min(double a, double b, double c)
{
    double m = a;
    if (b < m) m = b;
    if (c < m) m = c;
    return m;
}

double min_f(double a, double b, double (*f)(double), double eps)
{
double x1, x2, x3, f1, f2, f3, m;

while(fabs(a-b) > eps && fabs(a-b) > eps * fabs(a+b)/2)
{
x2 = (a + b)/2;
x1 = (a + x2)/2;
x3 = (x2 + b)/2;

f1 = f(x1); f2 = f(x2); f3 = f(x3);

m = min(f1, f2, f3);

if(fabs(m - f1) < 1e-15) b = x2;
else if(fabs(m - f2) < 1e-15) {a = x1; b = x3;}
else a = x2;
}

x2 = (a + b)/2;

return x2;
}

int main()
{
double a = -10, b = 10, x_min, eps = 1e-11;

x_min = min_f(a, b, f, eps);

printf("x_min = %g\nf(x_min) = %g", x_min, f(x_min));

return 0;
}