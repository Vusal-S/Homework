#include <stdio.h>
#include <math.h>

double my_sin(double x)

{
	
	double sum=0, h, eps=1.e-16;
	int i=0;
	h=x;

	do
	{
		sum += h;
		h *= -x * x / ((2*i+2)*(2*i+3));
		i++;
	}
	while(fabs(h) > eps);

	return sum;
}

int main(void)
{
	double a, x=1;
	
	a = my_sin(x);
	
	FILE *fout = NULL;
	if(!(fout = fopen("output.txt", "w"))) return 1;
	
	while(fabs(a/sin(x) -1) < 1.e-14)
	{
		fprintf(fout, "|  %g  |  %g  |  %g  |  %g  |\n", x, a, fabs(a - sin(x)), fabs(a/sin(x)-1));
		
		x ++;
		
		a = my_sin(x);
	}
	
	return 0;
}