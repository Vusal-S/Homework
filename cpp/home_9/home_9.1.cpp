#include <iostream>
#include "class.cpp"
using namespace std;

template<typename t1,typename t2>
class myclass{
	t1 a;
	t2 b;
	
	public:
	
	myclass(t1 a = 0, t2 b = 0) : a(a), b(b) {}
	
	friend istream &operator>>(istream &in, myclass &ob)
	{
		in >> ob.a >> ob.b;
	
		return in;
	}
	
	friend ostream &operator<<(ostream &out, myclass &ob)
	{
		out << ob.a << ", " << ob.b;
	
		return out;
	}
};

using newint=myclass<int, int>;
using newdouble=myclass<double, double>;

int main()
{
	int flag;
	newint a;
	List<newint> list;
	
	while(1)
	{
		cout << "1.Insert \n2.Delete \n3.Get \n4.Set \n5.StepForward \n6.GotoBeg \n7.AtBeg \n8.IsEmpty \n9.show \n0.Exit\n\n";
		
		cin >> flag;
		cout << endl;
		
		switch(flag)
		{
			case 0:
				exit(0);
			
			case 1:
				cin >> a;
				if (list.Insert(a)) cout << "error memory.\n\n";
				cout << endl << endl;
				break;
			
			case 2:
				if (list.Delete()) cout << "next is base.\n\n";
				break;
				
			case 3:
				if (list.Get(&a)) cout << "current is base.\n\n";
				else cout << a << endl << endl;
				break;
			
			case 4:
				cin >> a;
				if (list.Set(a)) cout << "current is base.\n\n";
				break;
				
			case 5:
				if (list.StepForward()) cout << "next is base.\n\n";
				break;
				
			case 6:
				list.GotoBeg();
				break;
				
			case 7:
				if (list.AtBeg()) cout << "Yes\n\n";
				else cout << "No\n\n";
				break;
				
			case 8:
				if (list.IsEmpty()) cout << "Yes\n\n";
				else cout << "No\n\n";
				break;
				
			case 9:
				list.show();
				cout << endl << endl;
				break;
				
			default:
				cout << "This number is not in the list.\n\n";
				break;
		}
	}
}
