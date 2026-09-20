#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int i, j, n1, m1, n2, m2;
	double **a, **b, **c;
	
	FILE *fin = fopen("input.txt", "r");
	
	if(fin == NULL) {printf("error 1"); return 1;}
	
	fscanf(fin, "%d%d", &n1, &m1); 
	
	a = (double**)malloc(n1 * sizeof(double*));
	
	
	for(i = 0; i < n1; i++)
	{
		a[i] = (double*)malloc(m1 * sizeof(double*));
		
		for(j = 0; j < m1; j++)
		{
			if(fscanf(fin, "%lf", &a[i][j])!=1) {printf("error 2"); return 2;}
		}
	}
	
	fscanf(fin, "%d%d", &n2, &m2);
	
	if(n1 != n2 || m1 != m2) {printf("error 4"); return 4;}
	
	b = (double**)malloc(n1 * sizeof(double*));
	c = (double**)malloc(n1 * sizeof(double*));
	
	
	for(i = 0; i < n1; i++)
	{
		b[i] = (double*)malloc(m1 * sizeof(double));
		
		for(j = 0; j < m1; j++)
		{
			if(fscanf(fin, "%lf", &b[i][j])!=1)
				{printf("error 5"); return 5;}
		}
	}
	
	
	for(i = 0; i < n1; i++)
	{
		c[i] = (double*)malloc(m1 * sizeof(double));
		
		for(j = 0; j < m1; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	
	for(i = 0; i < n1; i++)
	{
		for(j = 0; j < m1; j++)
		{
			printf("%g ", c[i][j]);
		}
		
		printf("\n");
	}
	
	
	return 0;
}
