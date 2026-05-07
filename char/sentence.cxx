#include <stdio.h>

int GetWord(FILE *f, char *word, char *delim, int ff);

int main(void)
{
 char word[50];
 int flag=0, ff=1;
 
 char delim[]={',',';',':',' ','(',')','[',']','-','+','*','/','\n','\0'};
 
 FILE *f=fopen("input.txt","r");
 
 int kol=0;
 
 while((flag=GetWord(f,word,delim, ff)) != 1)
       {
       ff=0;
		if (flag==-1) kol++;
		if (flag==0) ff=1;
       } 
 printf("%d\n",kol);
 
 return 0;
}

int GetWord(FILE *f, char *word, char *delim, int ff)
{
 int k=0, flag=0, n=0;
 char c;
 
 word[0] = '\0';
 
 while(fscanf(f,"%c",&c)==1)
    {
	 if (c=='?' || c=='!' || c=='.')
	 {
	 	if (flag || ff==1)  {word[n]='\0'; return -1;}
	 	else continue;
	 }
	 k=0;
	 while (delim[k]!='\0')
	  {
	   if(c==delim[k]) break;
	   k++;
	  }
	  
     if(delim[k] == '\0') {flag=1; word[n++]=c;}
     
	 else  if(n>0) {word[n]='\0'; return 0;}
    }
    if (n>0 || ff==1) return -1;
    return 1;
}