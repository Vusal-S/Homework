#include <iostream>
using namespace std;

class myclass{
    
    int a;
    
    public:
    
    myclass(int x) : a(x) {}
    
    int show() {return a;}
};

int main()
{
    myclass ob(10);
    
    cout<<ob.show()<<endl;
    
    return 0;
}