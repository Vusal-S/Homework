#include <stdio.h>
#include <math.h>

double f0(double x)
{
	return 1;
}
double f1(double x)
{
	return x;
}
double f2(double x)
{
	return x * x;
}
double f3(double x)
{
	return x * x * x;
}
double f4(double x)
{
	return x * x * x * x;
}
double f5(double x)
{
	return pow(x, 5);
}
double f6(double x)
{
	return pow(x, 6);
}
double f7(double x)
{
	return pow(x, 7);
}
double f8(double x)
{
	return pow(x, 8);
}
double S(double (*f)(double), double a, double b)
{
	return ((b - a)/180) * (9*f(a)
	+ 49*f((a + b)/2 - sqrt(3.0/7.0)*(b - a) / 2)
	+ 64*f((a + b)/2)
	+ 49*f((a + b)/2 + sqrt(3.0/7.0)*(b - a)/2)
	+ 9*f(b));
}

int main()
{
	double R, a = 3, b = 37;

	R = (b - a) - S(f0, a, b);
	printf("m=0: R = %e\n", R);

	R = (b * b - a * a) / 2 - S(f1, a, b);
	printf("m=1: R = %e\n", R);

	R = (pow(b, 3) - pow(a, 3)) / 3 - S(f2, a, b);
	printf("m=2: R = %e\n", R);

	R = (pow(b, 4) - pow(a, 4)) / 4 - S(f3, a, b);
	printf("m=3: R = %e\n", R);

	R = (pow(b, 5) - pow(a, 5)) / 5 - S(f4, a, b);
	printf("m=4: R = %e\n", R);

	R = (pow(b, 6) - pow(a, 6)) / 6 - S(f5, a, b);
	printf("m=5: R = %e\n", R);

	R = (pow(b, 7) - pow(a, 7)) / 7 - S(f6, a, b);
	printf("m=6: R = %e\n", R);

	R = (pow(b, 8) - pow(a, 8)) / 8 - S(f7, a, b);
	printf("m=7: R = %e\n", R);

	R = (pow(b, 9) - pow(a, 9)) / 8 - S(f8, a, b);
	printf("m=8: R = %e\n", R);

	return 0;
}