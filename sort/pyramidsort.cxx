#include <stdio.h>
#include <stdlib.h>

void sort3(int *mas, int i, int last)
{
    int max = i;
    
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l <= last && mas[l] > mas[max]) max = l;
    if (r <= last && mas[r] > mas[max]) max = r;

    if (max != i)
    {
        int tmp = mas[i];
        
        mas[i] = mas[max];
        mas[max] = tmp;
        
        sort3(mas, max, last);
    }
}

void pyramid(int *mas, int last)
{
	for(int i=last/2-1; i>=0; i--) sort3(mas, i, last);
	
	for(int i=last-1; i>0; i--)
	{
		int tmp=mas[i];
		mas[i]=mas[0];
		mas[0]=tmp;
		
		sort3(mas, 0, i-1);
	}
}
	
int main()
{
	int kol=0;
	
	FILE *fin=NULL;
	//FILE *fout=NULL;
	if (!(fin=fopen("input.txt", "r"))) return 1;
	//if (!(fout=fopen("output.txt", "w"))) return 2;
	
	int mas[100];
	//if(!(mas=(int*)malloc(100*sizeof(int)))) return 3;
	
	while(fscanf(fin,"%d", &mas[kol]) == 1) kol++;
	
	pyramid(mas, kol);
	
	for(int i=0; i<kol; i++) printf("%d ",mas[i]);
	
	return 0;
}
