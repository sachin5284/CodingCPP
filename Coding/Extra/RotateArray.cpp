#include<iostream>
#include<vector>
using namespace std;
void swap(int &a, int &b)
{
    int temp =a;
    a=b;
    b=temp;
}
void ReverseArray(vector<int> &a,int l,int h)
{
    while(l<h)
    {
        swap(a[l],a[h]);
        l++;h--;
    }
}

void ReverseArray(vector<int> &a,int k)
{
    ReverseArray(a,0,k-1);
    ReverseArray(a,k,a.size()-1);
    ReverseArray(a,0,a.size()-1);
}

int main()
{
    vector<int> a={1,2,3,4,5,6,7};

    ReverseArray(a,2);

    for(auto it : a)
    {
        cout<<it<<endl;
    }
}