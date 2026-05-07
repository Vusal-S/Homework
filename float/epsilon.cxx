#include <stdio.h>

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

int main(void)
{
	float x=1.0, b; int i=0;
	double y=1.0, d;
	
	do
	{
		printf("%d: %e\n",i,x);
		printBits_float(&x); printf("\n");
		b=1+x;
		printBits_float(&b); printf("\n");
		x/=2.0; i--;
		
		b=1+x;
	}
	while( b>1.0 );
	
	b=1+x;
	printf("\n"); printBits_float(&b); printf("\n\n");
	
	i=0;
	
	do
	{
		printf("%d: %le\n",i,y);
		printBits_double(&y); printf("\n");
		d=1+y;
		printBits_double(&d); printf("\n");
		y/=2.0; i--;
		
		d=1+y;
	}
	while( d>1.0 );
	
	d=1+y;
	
	printf("\n"); printBits_double(&d); printf("\n");
	
	return 0;
}