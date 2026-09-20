#include <iostream>
using namespace std;

class myclass{
	
	int width;
	int height;
	
	public:
	
	void set_w(int w)	{width = w;}
	int get_w()	{return width;}
	
	void set_h(int h)	{height = h;}
	int get_h()	{return height;}
};

int main()
{
	myclass rectangle;
	
	rectangle.set_h(10);
	rectangle.set_w(20);
	
	cout<<"height = "<<rectangle.get_h()<<endl;
	cout<<"width = "<<rectangle.get_w()<<endl;
	
	return 0;
}
