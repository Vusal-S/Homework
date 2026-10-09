#include <iostream>
using namespace std;

class myclass
{
	int size;
	int *a;

  public:
	myclass(int size) : size(size)
	{
		a = new int[size];
	}

	~myclass()
	{
		delete[] a;
	}

	void put(int i, int number)
	{
		a[i] = number;
	}

	friend ostream &operator<<(ostream &out, const myclass &ob);
	friend istream &operator>>(istream &in, myclass &ob);
};

ostream &operator<<(ostream &out, const myclass &ob)
{
	out << "[ ";
	for (int i = 0; i < ob.size; i++)
	{
		out << ob.a[i] << " " ;
	}
	out << "]";
	return out;
}

istream &operator>>(istream &in, myclass &ob)
{
	for (int i = 0; i < ob.size; i++)
	{
		in >> ob.a[i];
	}
	return in;
}

int main(void)
{
	myclass ob1(3);

	cout << "Введите 3 числа для массива: ";
	cin >> ob1;

	cout <<  ob1 << endl;

	return 0;
}
