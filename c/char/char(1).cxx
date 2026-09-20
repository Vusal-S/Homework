#include <stdio.h>
int main()
{
	char c;
	int buk=0, BUK=0, num=0;
	FILE *fin=fopen("input.txt", "r");
	while ((c=fgetc(fin))!=EOF)
	{
		if (c>='A' && c<='Z') BUK++;
		if (c>='a' && c<='z') buk++;
		if (c>='0' && c<='9') num++;
	}
	printf("%d, %d, %d", BUK, buk, num);
	return 0;
}