#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int getConsecutiveOnes(int n)
{
    int allPossibleCases = pow(2,n);
    
    vector<int> a(5,1);//for 0's
    vector<int> b(5,1);//for 1's

    for(int i=1;i<n;i++)
    {
        a[i]=a[i-1]+b[i-1];
        b[i]=a[i-1];
    }

    return allPossibleCases - (a[n-1]+b[n-1]);
}

int main()
{
    cout<<getConsecutiveOnes(4)<<endl;
    return 0;
}