#include <stdio.h>
#include <math.h>

double fact(int n)
{
	double y =1;
	
	for(int i=1; i <= n; i++) y *= i;
	
	return y;
}

double lagr(double *x, double *f, double t, int n)
{
	double L=0.0, F;
	
	for(int i=0; i<n; i++)
	{
		F=1.0;
		
		for(int j=0; j<n; j++)
		{
			if(j != i) F *= (t - x[j])/(x[i] - x[j]);
		}
		
		L += f[i]*F;
	}
	
	return L;
}

int main(void)
{
	double t[100000], x[1000], f[1000];
	int n[] = {2 ,3 ,4 ,5 , 6, 7, 8, 9, 10, 11, 12, 13, 14, 17, 33, 65, 101};
	
	int i, k=0;
	double err, max, grade;
	
	for(i=0; i<100000; i++) t[i] = (double)i/100000;
	
	
	while(k < 17)
	{
		err = 0; max = 0;
		grade = 1.0/(pow(2,n[k])*fact(n[k]));
		
		for(i=0; i < n[k]; i++)
		{
			x[i] = (double)i/(n[k] -1);
			f[i] = sin(x[i]);
		}
	
		for(i=0; i<100000; i++)
		{
			err = fabs(lagr(x, f, t[i], n[k]) - sin(t[i]));
			
			if(max < err) max = err;
		}
		
		printf("|  %d  |  %e  |  %e  | \n", n[k], max, grade);
		
		k++;
	}
	
	return 0;
}