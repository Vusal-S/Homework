#include <stdio.h>
unsigned search(unsigned a, int i)
{
	if ((a>>i) & 1u) return 1;
	return 0;
}
unsigned change(unsigned a, int i, int j)
{
	a = a & ~(1u << i);
	return a | (1u << j);
}
int main()
{
	unsigned number;
	int i, j, a, b;
	FILE *fin = fopen("input.txt", "r");
	FILE *fout = fopen("output.txt", "w");
	
	printf("i: "); scanf("%d", &i); printf("\n");
	printf("j: "); scanf("%d", &j); printf("\n");
	
	while (fscanf(fin, "%u", &number)==1)
	{
		a = search(number, i);
		b = search(number, j);
		if (a>b) number = change(number, i, j);
		else if (b>a) number = change(number, j, i);
		fprintf(fout, "%u ", number);
	}
	return 0;
}