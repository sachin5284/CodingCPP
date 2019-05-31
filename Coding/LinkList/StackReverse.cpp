#include<iostream>
#include<stack>
using namespace std;

void ReverseStack(stack<int> &s,int n)
{
    if(n==1)return;

    int x = s.top();s.pop();
    int y = s.top();s.pop();

    s.push(x);

    ReverseStack(s,n-1);
    s.push(y);
}

void ReverseStack(stack<int> &s)
{
    int n =s.size();
    for(int i=n;i>1;i--)
    {
        ReverseStack(s,i);
    }
}
void printStack(stack<int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}
int main()
{
    stack<int> s({1,2,3,4,5,6});
    ReverseStack(s);
    printStack(s);
    return 0;
}