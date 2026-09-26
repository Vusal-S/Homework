#include <iostream>
#include <cstdlib>
using namespace std;

class myclass{
    
    double *a;
    
    public:
    
    myclass(int size);
    
    ~myclass() 
    {
        cout<<"B деструкторе"<<endl;
        
        free(a);
    }
};
    
myclass::myclass(int size)
{
    a=(double*)malloc(size * sizeof(double));
    
    if(!a)
    {
        cout<<"Память не выделена" <<endl;
        
        exit(1);
    }
}

int main()
{
    for(int i=0; i<1000000;i++)
    {
        cout<<i<<": ";
        myclass ob(5000000);
    }
    
    return 0;
}