#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	double *a, *b, *c;
	int k, i, j;
	
	
	int n1, m1, n2, m2;
	
	FILE *fin = fopen("input.txt", "r");
	
	if(fin == NULL) {printf("error 1"); return 1;}
	
	fscanf(fin, "%d%d", &n1, &m1); 
	
	a = (double*)malloc(n1 * m1 * sizeof(double));
	
	
	for(i = 0; i < n1; i++)
		for(j = 0; j < m1; j++)
		{
			if(fscanf(fin, "%lf", &a[i * m1 + j])!=1) {printf("error 2"); return 2;}
		}
	
	fscanf(fin, "%d%d", &n2, &m2);
	
	if(m1 != n2) {printf("error 3"); return 3;}
	
	b = (double*)malloc(n2 * m2 * sizeof(double));
	c = (double*)malloc(n1 * m2 * sizeof(double));
	
	
	for(i = 0; i < n2; i++)
		for(j = 0; j < m2; j++)
		{
			if(fscanf(fin, "%lf", &b[i * m2 + j])!=1) {printf("error 4"); return 4;}
		}
	
	for(i = 0; i < n1; i++)
		for(j = 0; j < m2; j++)
		{
			c[i * m2 + j] = 0;
			
			for(k =0; k < m1; k++)
				c[i * m2 + j] += a[i * m2 + k] * b[k * m1 + j];
		}
	
	for(i = 0; i < n1; i++)
	{
		for(j = 0; j < m2; j++)
		{
			printf("%g ", c[i * m2 + j]);
		}
		
		printf("\n");
	}
	/*
	
	int n;
	
	scanf("%d", &n); printf("\n");
	
	a = (double*)malloc(n * n * sizeof(double));
	b = (double*)malloc(n * n * sizeof(double));
	c = (double*)malloc(n * n * sizeof(double));
	
	
	for (i = 0; i < n; i++)
		for(j = 0; j < n; j++)
		{
			if (i >= n - 1 - j) a[i*n + j] = n-i;
		
			else a[i*n +j] = 1 + j;
		}
	
	for (i = 0; i < n; i++)
		for(j = 0; j < n; j++)
		{
			if(i + j == n-1 && i <= n-2) b[i*n+j] = 2;
			
			else if(i == n-1 && j == 0) b[i*n+j] = 1;
			
			else if(fabs(i+j-n+1) == 1) b[i*n+j] = -1;
			
			else b[i*n+j] = 0;
		}
	
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
		{
			c[i * n + j] = 0;
			
			for(k =0; k < n; k++)
				c[i * n + j] += a[i * n + k] * b[k * n + j];
		}
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%g ", c[i * n + j]);
		}
		
		printf("\n");
	}
	*/
	
	return 0;
}