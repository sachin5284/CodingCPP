#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;
struct _comparer
{
    bool operator()(const int&  a, const int & b) const {return a<b;}
};

struct _hash
{
    size_t operator()(const pair<int,int>& a)const {
        size_t h1 = std::hash<std::string>{}(to_string(a.first));
        size_t h2 = std::hash<std::string>{}(to_string(a.second));
        return h1^(h2<<1);
    }
};

struct _equal
{
    bool operator()(const pair<int,int>& a,const pair<int,int>& b) const {
        return a.first==b.first && a.second==b.second;
    }
};

//int sum=0;
int main()
{
    static int sum=0;
    vector<int> v(10,1);
    //int sum=0;
    for_each(v.begin(),v.end(),[](int i){sum=sum+i;});

    v[9]=11;
    sort(v.begin(),v.end(),_comparer());
    for(auto i:v)cout<<i<<endl;
    //cout<<sum<<endl;

}