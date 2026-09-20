#include <stdio.h>
#include <math.h>

int kvadr(double b, double c, double *x_1, double *x_2)

{
	double d;

	d=b*b-4*c;

	if(d<0) return 0;
	
	*x_1=(-b+sqrt(d))/2;
	*x_2=(-b-sqrt(d))/2;

	return 1;
}

int main()
{
	double b, c, x1, x2, x_1, x_2;
	
	scanf("%lf%lf", &x1, &x2);
	
	b=-(x1+x2);
	c=x1*x2;
	
	if (!kvadr(b, c, &x_1, &x_2)){printf("Нет действительных корней\n"); return 1;}
	
	printf("x1=%g: |  x_1=%g  |  %g  |  %g  |\n", x1, x_1, fabs(x1-x_1), fabs(x_1/x1 - 1));
	
	printf("x2=%g: |  x_2=%g  |  %g  |  %g  |\n", x2, x_2, fabs(x2-x_2), fabs(x_2/x2 - 1));
	
	return 0;
}