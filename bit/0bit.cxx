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
	double a=1.0; float b=1.0; int i=0;
	
	do
	{
		printf("%d: %e=\t",i,b);
		printBits_float(&b);
		printf("\n");
		b/=2.0; i--;
	}
	while( b>0 );
	
	printf("b=%e\n\n",b);
	i=0;
	
	do
	{
		printf("%d: %le=\t",i,a);
		printBits_double(&a);
		printf("\n");
		a/=2.0; i--;
	}
	while( a>0 );
	
	printf("a=%e\n",a);
	
	return 0;

}