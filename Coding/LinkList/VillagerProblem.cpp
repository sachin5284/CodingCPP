#include <bits/stdc++.h> 
using namespace std;

int getVulrenableRow(vector<vector<int> > a)
{
    int col =0;
    int size = a[0].size();
    int min = INT_MAX;
    int result =INT_MIN;
    int count=0;
    int temp =0;
    for(auto row:a)
    {
        if(row[col]==1 && col<size)
        {
            while(row[col]==1)
            {
                col++;
            }
            if(col<min)
            {
                min = col;
                result = count;
            }
        }
        else
        {
            while(row[col]==0 && col>=0)
            {
                col--;
            }
            if(col+1<min)
            {
                min =col+1;
                result = count;
            }
            
        }
        count++;
        
    }
    return result;
}
int main()
{
    vector<vector<int> > a ={{1,1,0,0},{1,1,0,0},{1,1,1,0}};
    cout<<getVulrenableRow(a);
}