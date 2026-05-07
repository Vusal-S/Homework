#include <stdio.h>
#include <string.h>
int main()
{
	char str1[100], str2[100];
	
	int len, i;
	
	FILE *fin=fopen("input.txt","r");
	
	fgets(str1, 100, fin);
	
	len = strlen(str1);
	
	for(i=0; i<len; i++)
	{
		str2[i]=str1[i];
	}
	str2[i]='\0';
	
	fputs(str2, stdout);
	
	return 0;
}