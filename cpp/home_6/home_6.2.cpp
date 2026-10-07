#include <iostream>
#include <string>
using namespace std;

class Flat{
  
	int price = 25000;
	friend class Person;
};

class Cat{
  
	string name = "Барсик";
	friend class Person;
};

class Phone{
	
	int battery = 51;
	friend class Person;
};

class Person{
  
  public:
  
	void checkEverything(Flat f, Cat c, Phone p)
	{
		cout << "Цена квартиры: " << f.price << " USD" << endl;
		cout << "Имя кота: " << c.name << endl;
		cout << "Заряд телефона: " << p.battery << "%" << endl;
	}
};

int main()
{
	Flat myFlat;
	Cat myCat;
	Phone myPhone;
	Person me;

	me.checkEverything(myFlat, myCat, myPhone);

	return 0;
}
