#include <stdio.h>
unsigned bit0(unsigned a, int j)
{
	return a & ~(1u << j);
}
unsigned bit1(unsigned a, int i)
{
	return a | (1u << i);
}
int main()
{
	unsigned number;
	int i, j;
	FILE *fin = fopen("input.txt", "r");
	FILE *fout = fopen("output.txt", "w");
	
	printf("i: "); scanf("%d", &i); printf("\n");
	printf("j: "); scanf("%d", &j); printf("\n");
	
	while (fscanf(fin, "%u", &number)==1)
	{
		number = bit1(number, i);
		number = bit0(number, j);
		fprintf(fout, "%u ", number);
	}
	return 0;
}