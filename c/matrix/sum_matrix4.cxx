#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, n1, m1, n2, m2;
    double **a, **b, **c;

    FILE *fin = fopen("input.txt", "r");
    if (fin == NULL) { printf("error 1"); return 1; }

    fscanf(fin, "%d%d", &n1, &m1);

    a = (double**)malloc(m1 * sizeof(double*));
    b = (double**)malloc(m1 * sizeof(double*));
    c = (double**)malloc(m1 * sizeof(double*));

    for (j = 0; j < m1; j++)
    {
        a[j] = (double*)malloc(n1 * sizeof(double));
        b[j] = (double*)malloc(n1 * sizeof(double));
        c[j] = (double*)malloc(n1 * sizeof(double));
    }

    for (i = 0; i < n1; i++)
        for (j = 0; j < m1; j++)
            if (fscanf(fin, "%lf", &a[j][i]) != 1) {printf("error 2"); return 2;}

    fscanf(fin, "%d%d", &n2, &m2);
    if (n1 != n2 || m1 != m2) {printf("error 4"); return 4;}

    for (i = 0; i < n1; i++)
    	for (j = 0; j < m1; j++)
            if (fscanf(fin, "%lf", &b[j][i]) != 1) {printf("error 2"); return 2;}

    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < m1; j++)
        {
            c[j][i] = a[j][i] + b[j][i];
            
            printf("%g ", c[j][i]);
        }
        
        printf("\n");
    }

    return 0;
}
