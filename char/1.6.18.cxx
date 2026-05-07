#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char surname[50];
	char name[50];
	int id;
	int dq;
} student;

int compare(const void *a, const void *b)
{
	int i, l1, l2;
	
	student ta = *(const student*)a;
	student tb = *(const student*)b;
	
	l1=strlen(ta.surname);
	l2=strlen(tb.surname);
	
	for (i=0; i<l1 && i<l2; i++)
		if (toupper(ta.surname[i]) != toupper(tb.surname[i]))
			return toupper(ta.surname[i]) - toupper(tb.surname[i]);
		
	if(l1!=l2) return l1-l2;
	
	return ta.id - tb.id;
}
int main ()
{
	int n, i;
	student *mas=NULL;
	FILE *fin=NULL;
	
	if(!(fin=fopen("input.txt","r"))) return -1;
	
	fscanf(fin,"%d", &n);
	
	if (n<0) {printf("n<0"); return -3;}
	
	if (!(mas=(student*)malloc(n*sizeof(student)))) return -2;
	
	for (i=0; i<n; i++) 
		if (fscanf(fin, "%s%s%d%d", mas[i].surname, mas[i].name, &mas[i].id, &mas[i].dq)!=4)
		{
			free(mas);
			fclose(fin);
			printf("ошибка при чтении");
			return -2;
		}
	qsort(mas, n, sizeof(student), compare);
	
	for (i=0; i<n; i++)
		if (mas[i].dq >= 1000)
			printf("%s %d\n", mas[i].surname, mas[i].id);
	return 0;
}	