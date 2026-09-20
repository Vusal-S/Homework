#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	
	if(!fin)
	{
		cout<<"File did not opened"<<endl;
		return 1;
	} 
	
    double x;
    double sum = 0;

    while(fin>>x)
    	sum += x;
	
	if(fin.eof())
	{
	    cout<<"End of file"<<endl;
	    cout<<"sum = "<<sum<<endl;
	}  
	else cout<<"Error"<<endl;
	
	return 0;
	}