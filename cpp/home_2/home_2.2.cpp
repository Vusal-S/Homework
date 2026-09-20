#include <iostream>
using namespace std;

namespace mymath{
	int fact = 1;
	
	int factorial(int n){
		while (n > 1)
		{
		    fact *= n;
		    n--;
		}
		return fact;
	}
}

int main(int argc, char **argv)
{
	int n;
	
	if (argc < 2)
	{
		cout<<"Ошибка, число не введено."<<endl;
		return 1;
	}
	
	n = stoi(argv[1]);
	
	cout<<mymath::factorial(n)<<endl;
	
	return 0;
}
