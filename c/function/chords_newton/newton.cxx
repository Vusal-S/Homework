#include <stdio.h>
#include <math.h>

int nf;

double g(double x)
{
	nf++;
	return exp(1-x)-1;
}
double dg(double x)
{
	double h=1.e-7;
	nf--;
	
	return (g(x+h)-g(x))/h;
}
int root_newton(double *x, double x0,double (*f)(double), double (*df)(double), double epsilon)
{
	double dfc, fx0, fc, c[2];
	int i=0, k;
	
	c[0]=x0; fx0=f(x0);
	dfc=df(x0); fc=fx0;
	
	if(fabs(fx0)<epsilon){*x=x0; return 1;}
	
	for(k=1; k<30; k++)
	{
		i=!i;
		c[i]= c[!i] - fc/dfc;
		fc=f(c[i]); dfc = df(c[i]);
		
		if(fabs(fc)<epsilon){*x=c[i]; return k+1;}
		if(fabs(c[1]-c[0])<epsilon){*x=c[i]; return k+1;}
	}
	*x=c[i];
	
	return k;
}

int main()
{
	double x=1, x_p; int res;
	
	FILE *fout = NULL;
	if(!(fout = fopen("output.txt", "w"))) return 1;
	
	nf=0;
	res=root_newton(&x_p, -1, g, dg, 1.e-15);
	
	if(res)
	{
		fprintf(fout, " x_p=%lg\n число итераций=%d\n",x_p,res-1);
		fprintf(fout, " число обращений к функции=%d\n",nf);
		fprintf(fout, " abs=%g\n otn=%g\n", fabs(x-x_p), fabs(x_p/x - 1));
	}
	else printf(" метод не применим\n");
	
	return 0;
}