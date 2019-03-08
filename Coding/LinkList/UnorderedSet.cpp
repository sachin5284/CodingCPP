#include<iostream>
#include<unordered_set>

using namespace std;

int main()
{
    unordered_set<int> s={1,2,3,4,5,6,7,8,9,0};
    unordered_set<int> :: iterator it;
    s.insert(11);
    for(it=s.begin();it!=s.end();++it)
    {
        cout<<(*it)<<endl;
    }
    if(s.find(11) != s.end())
        cout<< (*s.find(11));

    return 0;
}