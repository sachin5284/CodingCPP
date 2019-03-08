#include<iostream>
#include<set>
using namespace std;

int main()
{
    set<int> s ={11,2,3,4,5,6,7,8,9,9};

    for(auto element : s)
    {
        cout<<element<<endl;
    }

    if(s.find(11)!=s.end())
    {
        cout<<"number is present...!!"<<endl;
    }
}