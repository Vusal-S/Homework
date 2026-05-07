#include <stdio.h>
int kol(unsigned a)
{
	int i, kol=0;
	for (i=31; i>=0; i--) if ((a>>i)&1) break;
	
	for (; i>=0; i--) if (!((a>>i)&1)) kol++;
	return kol;
}
int main()
{
	unsigned number, inumber;
	int i, koln;
	FILE *fin=NULL;
	fin = fopen("input.txt","r");
	scanf("%d", &number);
	koln = kol(number);
	while (fscanf(fin, "%d", inumber))
	{
		if (kol(inumber)>koln) printf("%d ", inumber);
	}
	return 0;
}