#include <stdio.h>
#include <math.h>

double my_exp(double x)

{
	if(x<0) return 1.0 / my_exp(-x);
	
	double sum=1.0, h, eps=1.e-16;
	int i=2;
	h=x;

	do
	{
		sum+=h;
		h*=x/i;
		i++;
	}
	while(fabs(h)>eps);

	return sum;
}

int main(void)
{
	double a;
	
	FILE *fout = NULL;
	if(!(fout = fopen("output.txt", "w"))) return 1;
	
	double mas[9] = {1, 10, 40, 50, -1, -10, -40, -50, -65};
	
	for (int i=0; i<9; i++)
	{
		a = my_exp(mas[i]);
		
		fprintf(fout, "%g  |  %g  |  %g  |  %g\n", mas[i], a, fabs(a - exp(mas[i])), fabs(a/exp(mas[i])-1));
	}
	
	return 0;
}