#include<iostream>
using namespace std;

int Add(int x, int y)
{
    return x+y;
}

int main()
{
    int myvar = 25;
    int (*func_ptr)(int,int) = &Add;
    cout<<(*func_ptr)(1,2)<<endl; 
    //address is stored by pointer and accessed by &
    int* foo = &myvar;
    int ** food = &foo;
    //cout<<**food<<endl;
}

