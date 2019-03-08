#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Point
{
        const static vector<int> b;

};
int main()
{
    map<int,int> m= {{1,2},{2,3},{45,5}};
    m.insert({4,5});
    for(auto element : m)
    {
        cout<<element.first<<" "<<element.second<<endl;
    }
}
