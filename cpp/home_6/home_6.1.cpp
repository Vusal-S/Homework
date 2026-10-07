#include <iostream>
using namespace std;

class myclass {
   
    int n, d;

	public:
    
    myclass(int i, int j) : n(i), d(j) {}

    friend bool isfactor(myclass ob);
};


bool isfactor(myclass ob)
{
    return (ob.n * ob.d) % 5 == 0;
}

int main(void)
{
    myclass ob1(10, 2);
    
    if (isfactor(ob1)) 
        cout << "произведение делится на 5" << endl;
    else 
        cout << "произведение не делится на 5" << endl;
      
    return 0;
}
