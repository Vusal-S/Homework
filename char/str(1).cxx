#include <stdio.h>
int main()
{
	char str[100];
	int kol=0;
	FILE *fin=fopen("input.txt","r");
	fgets(str, 100, fin);
	
	while(str[kol]!='\0' && str[kol]!='\n') kol++;
	printf("%d", kol);
	return 0;
}