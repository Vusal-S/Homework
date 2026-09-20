#include <iostream>
using namespace std;

namespace mymath{
	double fact = 1;
	
	double factorial(double n){
		while (n > 1)
		{
		    fact *= n;
		    n--;
		}
		return fact;
	}
}

int main(void)
{
	double n;
	
	cin>>n;
	cout<<mymath::factorial(n)<<endl;
	
	return 0;
}



