#include <stdio.h>
int main()
{
    char c;
    int kolm=0, kol=0, flag=0;
    FILE *fin = fopen("input.txt", "r");
    while ((c=fgetc(fin))!=EOF)
    {
    	switch (flag)
    	{
    		case 0:
    			if (c=='A') flag++;
    			break;
    			
    		case 1:
    			if (c=='A') flag = 1;
    			
    			else if (c=='B') flag++;
    			
    			else {kol = 0; flag = 0;}
    			break;
    			
    		case 2:
    			if (c=='A') {flag = 1; kol = 0;}
    			
    			else if (c=='C') flag++;
    			
    			else {kol = 0; flag = 0;}
    			break;
    			
    		case 3:
    			if (c=='A') {flag = 1; kol = 0;}
    			
    			else if (c=='D') {flag=0; kol++;}
    			
    			else {kol = 0; flag = 0;}
    			break;
    	}
    	if (kolm<kol) kolm=kol;
    }
    printf("%d", kolm*4);
    return 0;
}