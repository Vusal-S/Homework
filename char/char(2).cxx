#include <stdio.h>
int main()
{
	char c;
	FILE *fin=fopen("input.txt", "r");
	FILE *fout=fopen("output.txt", "w");
	while ((c=fgetc(fin))!=EOF)
	{
		if (c>='A' && c<='Z') c = c - 'A' +'a';
		fprintf(fout, "%c", c);
	}
	return 0;
}