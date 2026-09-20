#include <stdio.h>

int main()
{
	float a;
	
	scanf("%f", &a);
	printf("%f %.2f %e %.3e %g\n", a, a, a, a, a);
	
	double b;
	
	scanf("%lf", &b);
	printf("%lf %lg\n", b, b);
	
	return 0;
}