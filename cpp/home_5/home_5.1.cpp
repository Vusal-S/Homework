#include <iostream>
using namespace std;

class massiv
{
	int size;

	int *a;

  public:
	massiv(int size) : size(size)
	{
		a = new int[size];
	}

	void put(int i, int number) { a[i] = number; }

	void show()
	{
		for (int i = 0; i < size; i++)
			cout << i << ":" << a[i] << endl;
	}

	massiv(const massiv &temp_ob)
	{
		this->size = temp_ob.size;

		this->a = new int[size];

		for (int i = 0; i < size; i++)
			this->a[i] = temp_ob.a[i];
	}
};

int main()
{
	massiv ob(10);

	for (int i = 0; i < 10; i++)
		ob.put(i, i);

	massiv ob2 = ob;

	for (int i = 0; i < 10; i++)
		ob2.put(i, 10 - i);

	ob.show();

	cout << endl;

	ob2.show();

	return 0;
}