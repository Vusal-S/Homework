#include <iostream>
using namespace std;

bool right()
{
	cout << "Правая сторона сработала" << endl;
	
	return true;
}

int main()
{
	bool left = 0;
	
	cout << "left = 0:" << endl;
	if (left && right())	{}
	else	{left = 1;}
	
	
	cout << "left = 1:" << endl;
	if (left && right())	{}
	else	{left = 1;}
	
	return 0;
}