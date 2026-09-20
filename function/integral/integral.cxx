#include <stdio.h>
#include <math.h>

double f1(double x) { return sin(x); }
double f2(double x) { return 1.0/x; }
double f3(double x) { return 10.0/(1+25*x*x); }

double Si(double (*f)(double), double a, double b)
{
    return ((b - a)/12.0) * (f(a)
        + 5*f((a+b)/2.0 - (b-a)/(2.0*sqrt(5.0)))
        + 5*f((a+b)/2.0 + (b-a)/(2.0*sqrt(5.0)))
        + f(b));
}

double Integrate(double (*f)(double), double a, double b, double eps, double *R1, double *R2, int *kol)
{
    double I = 0,  h = 0.1, s1, s2, delta, xi;
    *kol = 0;
    *R1 = 0;
    *R2 = 0;
    
    while (a < b)
    {
        if (a + h > b) h = b - a;

        s1 = Si(f, a, a+h);
        s2 = Si(f, a, a+h/2.0) + Si(f, a+h/2.0, a+h);
        
        delta = (s2 - s1) / 63.0;

        if (fabs(delta) < eps)
        {
            I += s2;
            *R1 += fabs(delta);
            *R2 += delta;
            a += h;
            (*kol)++;
        }
        
        xi = pow(fabs(delta)/eps, 1.0/7.0);
        if (xi > 10.0) xi = 10.0;
        if (xi < 0.1) xi = 0.1;
        
        h = 0.95 * h / xi;
    }
    
    *R2 = fabs(*R2);
    
    return I;
}

int main()
{
    double R, R1=0, R2=0, I, eps = 1e-9;
    double a, b;
    int kol;
    
    a = -1, b = 10.0;
    
    I = Integrate(f1, a, b, eps, &R1, &R2, &kol);
    R = fabs(-cos(b) + cos(a) - I);
    
    printf("sin(x):\nI = %g    kol = %d\nR = %g\n", I, kol, R);
    printf("Гарантирующая: %g\n", R1);
    printf("Средневзвешенная: %g\n\n", R2);

    a = 5.0, b = 20.0;
    
    I = Integrate(f2, a, b, eps, &R1, &R2, &kol);
    R = fabs(log(b) - log(a) - I);
    
    printf("1/x:\nI = %g    kol = %d\nR = %g\n", I, kol, R);
    printf("Гарантирующая: %g\n", R1);
    printf("Средневзвешенная: %g\n\n", R2);

    a = -10.0, b = 10.0;
    
    I = Integrate(f3, a, b, eps, &R1, &R2, &kol);
    R = fabs(2*(atan(5.0*b) - atan(5.0*a)) - I);
    
    printf("10/(1+25*x*x)\nI = %g    kol = %d\nR = %g\n", I, kol, R);
    printf("Гарантирующая: %g\n", R1);
    printf("Средневзвешенная: %g\n\n", R2);

    return 0;
}