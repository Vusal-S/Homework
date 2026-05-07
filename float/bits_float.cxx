#include <stdio.h>

void printBits_float(void *a)
{
	int i; unsigned x;
	x = *(unsigned*)a;
	
	for(i=31; i>=0; i--)
	{
		if((x&((unsigned)1<<i))!=0) printf("1");
		else printf("0");
			
		if(i==31) printf(" ");
		
		if(i==23) printf(" ");
	}
}

int main()
{
	float a;
	
	scanf("%f", &a);
	printBits_float(&a);
	
	return 0;
}