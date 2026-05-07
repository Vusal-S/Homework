#include <stdio.h>
#include <math.h>

int nf;

int sign(double x)
{
	if(x>0)return 1;
	else if(x<0)return -1;
	return 0;
}

double g(double x)
{
	nf++;
	return atan(x);
}

int root_chords(double *x, double a, double b,double (*f)(double), double epsilon)
{
	double fa,fb,fc,c[2];
	int i=0,ifa,ifb,ifc,k;
	
	c[0]=a; c[1]=b; fa=f(a); fb=f(b);
	
	if(fabs(fa)<epsilon){*x=a; return 1;}
	if(fabs(fb)<epsilon){*x=b; return 1;}
	
	ifa=sign(fa); ifb=sign(fb);
	if(ifa*ifb != -1) return 0;
	
	for(k=1; fabs(c[1]-c[0])>epsilon; k++)
	{
		i=!i;
		c[i]=(a*fb-b*fa)/(fb-fa);
		fc=f(c[i]); ifc=sign(fc);
		
		if(fabs(fc)<epsilon){*x=c[i]; return k+1;}
		
		if(ifc*ifa==1){a=c[i]; fa=fc;}
		else {b=c[i]; fb=fc;}
	}
	*x=c[i];
	
	return k;
}

int main()
{
	double x=0, x_p; int res;
	
	FILE *fout = NULL;
	if(!(fout = fopen("output.txt", "w"))) return 1;
	
	nf=0;
	res=root_chords(&x_p, -2, 2, g, 1.e-15);
	
	if(res)
	{
		fprintf(fout, " x_p=%lg\n число итераций=%d\n",x_p,res-1);
		fprintf(fout, " число обращений к функции=%d\n",nf);
		fprintf(fout, " abs=%g\n otn=%g\n", fabs(x-x_p), fabs(x_p/x - 1));
	}
	else printf(" метод не применим\n");
	
	return 0;
}