#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int i, j, n1, m1, n2, m2;
	double *a, *b, *c;
	
	FILE *fin = fopen("input.txt", "r");
	
	if(fin == NULL) {printf("eror 1"); return 1;}
	
	fscanf(fin, "%d%d", &n1, &m1); 
	
	a = (double*)malloc(n1 * m1 * sizeof(double));

	
	for(i = 0; i < n1; i++)
	{
		for(j = 0; j < m1; j++)
		{
			if(fscanf(fin, "%lf", &a[i * m1 + j])!=1) {printf("eror 2"); return 2;}
		}
	}
	
	fscanf(fin, "%d%d", &n2, &m2);
	
	if(n1 != n2 || m1 != m2) {printf("eror 4"); return 4;}
	
	b = (double*)malloc(n2 * m2 * sizeof(double));
	c = (double*)malloc(n1 * m1 * sizeof(double));
	
	
	for(i = 0; i < n1; i++)
	{
		for(j = 0; j < m1; j++)
		{
			if(fscanf(fin, "%lf", &b[i * m1 + j])!=1) {printf("eror 2"); return 2;}
		}
	}
	
	
	for(i = 0; i < n1; i++)
	{
		for(j = 0; j < m1; j++)
		{
			c[i * m1 + j] = a[i * m1 + j] + b[i * m1 + j];
			
			printf("%g ", c[i * m1 + j]);
		}
		
		printf("\n");
	}
	
	
	
	return 0;
}
