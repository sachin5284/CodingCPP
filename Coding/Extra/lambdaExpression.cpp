#include<iostream>
#include<algorithm>
#include<list>
using namespace std;
template<class T>
T GetSum(T a,T b)
{
    T result;
    result= a+b;
    return result;
}
int main()
{
    list<int> a={7,6,4,3,6,8,22,4,5};
    int n=sizeof(a)/sizeof(int);
    a.sort( [](int a,int b){return a>b;});
    // for(int i : a)
    // {
    //     cout<<i<<endl;
    // }
    cout<<GetSum<int>(3,4)<<endl;
    return 0;
}