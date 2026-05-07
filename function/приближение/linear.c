#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void line(double *x, double *y, int n, double *a, double *b)
{
	double c1=0, c2=0, d11=0, d12=0, d21=0, d22=0;
	
	for(int i=0; i<n; i++)
	{
		c1 += x[i]*y[i];
		c2 += y[i];
		
		d11 += x[i]*x[i];
		d12 += x[i];
		d21 += x[i];
	}
	
	d22 = n;
	
	*b = (c1*d21 - c2*d11)/(d12*d21 - d11*d22);
	
	*a = (c1*d22 - c2*d12)/(d11*d22 - d21*d12);
}
int main()
{
	double err, x_min, x_max, eps, a, b, a_p, b_p;
	int n;
	
	double *x, *y;
	
	printf("n="); scanf("%d", &n);
	printf("eps=");scanf("%lf", &eps); printf("\n");
	
	printf("x_min=");scanf("%lf", &x_min);
	printf("x_max="); scanf("%lf", &x_max); printf("\n");
	
	printf("a=");scanf("%lf", &a);
	printf("b=");scanf("%lf", &b); printf("\n");
	
	if(!(x = (double*)malloc(n*sizeof(double)))) return 1;
	if(!(y = (double*)malloc(n*sizeof(double)))) return 2;
	
	for(int i=0; i<n; i++)
	{
		x[i] = x_min + ((x_max - x_min)*rand())/RAND_MAX;
		
		err = eps*((2.0*rand())/RAND_MAX -1);
		
		y[i] = a*x[i] + b + err;
	}
	
	line(x, y, n, &a_p, &b_p);
	
	printf("a_p = %g  |  %g  |  %g  |\n", a_p,  fabs(a-a_p), fabs(a_p/a -1));
	printf("b_p = %g  |  %g  |  %g  |",b_p, fabs(b-b_p), fabs(b_p/b -1));
	
	return 0;
}	
