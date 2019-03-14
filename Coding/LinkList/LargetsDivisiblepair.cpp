#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int a[] = {10,5,3,15,20};
    int size = sizeof(a)/sizeof(int);
    cout<<size<<endl;
    sort(a,a+size);
    vector<int> dp(size,1);
    for(int i=1;i<size;i++)
    {
        int last=i-1;
        while(last>=0)
        {
            if(a[i] % a[last]==0)
            {
                int val = dp[last]+1;
                dp[i]= val>dp[i]? val : dp[i];
            }
            last--;
        }
    }

    cout<<dp[size-1];
}