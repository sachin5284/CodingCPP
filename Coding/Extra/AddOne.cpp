#include<iostream>
#include<vector>

using namespace std;

void plusOne(vector<int> &A) {
    int size = A.size();
    int carry = 1;
    for(int i = size-1;i>=0;i--)
    {
        int tempCarry = (A[i]+carry)/10;
        int val = (A[i]+carry)%10;
        A[i]=val;
        carry=tempCarry;
        if(carry==0)break;
    }
    if(carry!=0)
    {
        A.insert(A.begin(),carry);
    }
    
    while(A[0]==0)
    {
        A.erase(A.begin());
    }    
}


int main()
{
    vector<int> a ={0};
    plusOne(a);

    for(auto e : a)
    {
        cout<<e<<endl;
    }
    
}