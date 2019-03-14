#include<iostream>
#include<stack>
using namespace std;

int Add(int x, int y)
{
    return x+y;
}

int main()
{
    stack<int> s;
    s.push(11);
    
    int myvar = 25;
    int (*func_ptr)(int,int) = &Add;
    cout<<(*func_ptr)(1,2)<<endl; 
    //address is stored by pointer and accessed by &
    int* foo = &myvar;
    int ** food = &foo;
    //cout<<**food<<endl;
}

