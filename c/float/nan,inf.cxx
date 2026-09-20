#include <stdio.h>

void printBits_double(void *a)
{
	int i; unsigned long x;
	x=*(unsigned long *)a;
	
	for( i=63; i>=0; i--)
	 {
		if((x & ((unsigned long)1 << i)) != 0)
			printf("1");
		else printf("0");

		if( i==63 ) printf(" ");

		if( i==52 ) printf(" ");
	}
}

void printBits_float(void *a)
{
	int i; unsigned x;
	x=*(unsigned *)a;
	
	for( i=31; i>=0; i--)
	 {
		if((x & ((unsigned )1 << i)) != 0)
			printf("1");

		else printf("0");

		if( i==31 ) printf(" ");

		if( i==23 ) printf(" ");
	 }
}

int main(void)
{
	float a;
	
	a = 0.0/0.0;
	printf("%f: ",a); printBits_float(&a); printf("\n");
	
	a = 1.0/0.0;
	printf("%f: ",a); printBits_float(&a); printf("\n");
	
	a = -1.0/0.0;
	printf("%f: ",a); printBits_float(&a); printf("\n");
	
	double b;
	
	b = 0.0/0.0;
	printf("%lf: ",b); printBits_double(&b); printf("\n");
	
	b = 1.0/0.0;
	printf("%f: ",b); printBits_double(&b); printf("\n");
	
	b = -1.0/0.0;
	printf("%f: ",b); printBits_double(&b); printf("\n");
	
	return 0;
}