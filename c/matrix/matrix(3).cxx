#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include <time.h>

int main()
{
	int i, j, n;
	double *a, *b;
	
	clock_t start_tick, end_tick;
    double dif_time;
	
	scanf("%d", &n); printf("\n");

	a = (double*)malloc(n * n * sizeof(double));
	b = (double*)malloc(n * n * sizeof(double));
	
	start_tick = clock();
	
	for (i = 0; i < n; i++)
	{
		for(j=0; j<n; j++)
		{
			if (i >= n - 1 - j) a[i*n + j] = n-i;
		
			else a[i*n +j] = 1 + j;
		}
	}
    
	for (i = 0; i < n; i++)
	{
		for(j=0; j < n; j++)
		{
			printf(" %g ", a[i*n+j]);
		}
		printf("\n");
	}
	
	for (i = 0; i < n; i++)
	{
		for(j=0; j < n; j++)
		{
			if(i + j == n-1 && i <= n-2) b[i*n+j] = 2;
			
			else if(i == n-1 && j == 0) b[i*n+j] = 1;
			
			else if(fabs(i+j-n+1) == 1) b[i*n+j] = -1;
			
			else b[i*n+j] = 0;
		}
	}
	
	printf("\n\n");
	
	for (i = 0; i < n; i++)
	{
		for(j=0; j < n; j++)
		{
			printf(" %g ", b[i*n+j]);
		}
		
		printf("\n");
	}
	
	end_tick = clock();
	
	dif_time = (double)(end_tick - start_tick) / CLOCKS_PER_SEC;
	
	printf("\n%f", dif_time);
	
	return 0;
}