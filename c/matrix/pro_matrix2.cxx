#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int k, i, j, n1, m1, n2, m2;
	double **a, **b, **c;
	/*
	FILE *fin = fopen("input.txt", "r");
	
	if(fin == NULL) {printf("error 1"); return 1;}
	
	fscanf(fin, "%d%d", &n1, &m1); 
	
	a = (double**)malloc(n1 * sizeof(double*));
	
	
	for(i = 0; i < n1; i++)
	{
		a[i] = (double*)malloc(m1 * sizeof(double));
		
		for(j = 0; j < m1; j++)
		{
			if(fscanf(fin, "%lf", &a[i][j])!=1) {printf("error 2"); return 2;}
		}
	}
	
	fscanf(fin, "%d%d", &n2, &m2);
	
	if(m1 != n2) {printf("error 3"); return 3;}
	
	b = (double**)malloc(n2 * sizeof(double*));
	c = (double**)malloc(n1 * sizeof(double*));
	
	
	for(i = 0; i < n2; i++)
	{
		b[i] = (double*)malloc(m2 * sizeof(double));
		
		for(j = 0; j < m2; j++)
		{
			if(fscanf(fin, "%lf", &b[i][j])!=1) {printf("error 4"); return 4;}
		}
	}
	
	for(i = 0; i < n1; i++)
	{
		c[i] = (double*)malloc(m2 * sizeof(double));
		
		for(j = 0; j < m2; j++)
		{
			c[i][j] = 0;
			
			for(k =0; k < m1; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
	}
	
	for(i = 0; i < n1; i++)
	{
		for(j = 0; j < m2; j++)
		{
			printf("%g ", c[i][j]);
		}
		
		printf("\n");
	}
	*/
	
	int n;
	
	scanf("%d", &n); printf("\n");
	
	a = (double**)malloc(n * sizeof(double*));
	b = (double**)malloc(n * sizeof(double*));
	c = (double**)malloc(n * sizeof(double*));
	
	
	for (i = 0; i < n; i++)
	{
		a[i] = (double*)malloc(n *  sizeof(double));
		
		for(j=0; j<n; j++)
		{
			if (i >= n - 1 - j) a[i][j] = n-i;
		
			else a[i][j] = 1 + j;
		}
	}
    
	
	for (i = 0; i < n; i++)
	{
		b[i] = (double*)malloc(n *  sizeof(double));
		
		for(j=0; j < n; j++)
		{
			if(i + j == n-1 && i <= n-2) b[i][j] = 2;
			
			else if(i == n-1 && j == 0) b[i][j] = 1;
			
			else if(fabs(i+j-n+1) == 1) b[i][j] = -1;
			
			else b[i][j] = 0;
		}
	}
	
	for(i = 0; i < n; i++)
	{
		c[i] = (double*)malloc(n * sizeof(double));
		
		for(j = 0; j < n; j++)
		{
			c[i][j] = 0;
			
			for(k =0; k < n; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
	}
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%g ", c[i][j]);
		}
		
		printf("\n");
	}
	
	return 0;
}