#include <stdio.h>
#include <stdlib.h>

void quicksort(int a[], int left, int right)
{
	int p, i, j, temp;
	i = left;
	j = right;
	p = a[(left + right) / 2];
	
	while (i <= j)
	{
	     while (a[i] < p) i++;
	     while (a[j] > p) j--;
	     if (i <= j)
    {
           temp = a[i];
           a[i] = a[j];
           a[j] = temp;
           i++;
           j--;
    }
    }
if (left < j)
    quicksort(a, left, j);
if (i < right)
   quicksort(a, i, right);
}

int main() {
    FILE *fp = fopen("input.txt", "r");
    if (!fp) {
        printf("error\n");
        return 1;}
int a[100];     
int n = 0;

while (fscanf(fp, "%d", &a[n]) == 1) {
      n++;}
quicksort(a, 0, n - 1);

printf("Sorted:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}