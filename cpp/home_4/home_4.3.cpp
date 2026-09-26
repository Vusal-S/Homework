#include <iostream>
#include <cstdlib>
using namespace std;

class myclass
{
	double *a;

  public:
	myclass(int size);

	~myclass()
	{
		cout << "B деструкторе" << endl;

		delete[] a;
	}
};

myclass::myclass(int size)
{
	a = new double[size];

	if (!a)
	{
		cout << "Память не выделена" << endl;

		exit(1);
	}
}

int main()
{
	for (int i = 0; i < 1000000; i++)
	{
		cout << i << ": ";
		myclass ob(5000000);
	}

	return 0;
}