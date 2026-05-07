#include <stdio.h>
#include <math.h>

int kvadr(double b, double c, double *x1, double *x2)

{
	double d;

	d=b*b-4*c;

	if(d<0) return 0;
	
	*x1=(-b+sqrt(d))/2;
	*x2=(-b-sqrt(d))/2;

	return 1;
}

int main()
{
	double b, c, b1, c1, x1, x2;
	
	scanf("%lf%lf", &b, &c);
	
	if (!kvadr(b, c, &x1, &x2)){printf("Нет действительных корней\n"); return 1;}
	
	b1=-(x1+x2);
	c1=x1*x2;
	
	printf("b=%g: |  b1=%g  |  %g  |  %g  |\n", b, b1, fabs(b-b1), fabs(b1/b - 1));
	
	printf("c=%g: |  c1=%g  |  %g  |  %g  |\n", c, c1, fabs(c-c1), fabs(c1/c - 1));
	
	return 0;
}