#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct pairs
{
    int first;
    int second;

    // pairs(int f, int s)
    // {
    //     this->first =f;
    //     this->second = s;
    // }
    bool operator >(const pairs &a) const{
        return (this->second - this->first) <
        (a.second - a.first);
    }

    bool operator <(const pairs &a) const{
        return (this->second - this->first) >
        (a.second - a.first);
    }

    bool operator ==(const pairs &a) const{
        return this->first == a.first &&
        this->second == a.second;
    }

};

int main()
{
    vector<pairs> v = { {0,4},{1,2,}, {2,5}, {2,3},{2,4}};
    sort(v.begin(),v.end());

    for(auto element: v)
        cout<<element.first<<"-"<<element.second<<endl;
    cout<<"Hello World..!!"<<endl;
    return 0;
}