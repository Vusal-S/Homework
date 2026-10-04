#include <iostream>
using namespace std;

class nmassiv
{
	int *a;
	int size;

  public:
  
  nmassiv(int size) : size(size)
	{
		try
		{
			a = new int[size];
		}
		catch (...)
		{
			cout << "Память не выделилась" << endl;
			exit(1);
		}
	}

	int &put(int i)
	{
		if (i < 0 || i >= size)
		{
			cout << "Выход за границы массива" << endl;
			exit(1);
		}

		return a[i];
	}

	int get(int i)
	{
		if (i < 0 || i >= size)
		{
			cout << "Выход за границы массива" << endl;
			exit(1);
		}

		return a[i];
	}
};

int main(void)
{
	nmassiv a(10);

	a.put(2) = 3;

	//a.put(25)=5;

	cout << a.get(2) << endl;

	return 0;
}