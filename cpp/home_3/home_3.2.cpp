#include <iostream>
using namespace std;

class myclass1{
    
    int a;
    
    public:
    
    myclass1()    {cout<<"Конструктор 1"<<endl;}
};

class myclass2{
    
    double a;
    
    myclass1 b;
    
    public:
    
    myclass2()    {cout<<"Конструктор 2"<<endl;}
};

int main()
{
    myclass2 ob;
    
    return 0;
}