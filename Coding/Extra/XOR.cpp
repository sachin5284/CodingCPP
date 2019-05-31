#include<iostream>
#include<vector>
using namespace std;

vector<int> repeatedNumber(const vector<int> &A) {
    int x,y;
    int size = A.size();
    int sum = size*(size+1)/2;
    int squareSum = size*(size+1)*(2*size+1)/6;
    
    int actualSum = 0;
    int actualSquareSum =0;
    
    for(int i=0;i<size;i++)
    {
        actualSum += A[i];
        actualSquareSum += A[i]*A[i];
    }
     int diff = actualSum - sum;
     int sums = (actualSquareSum - squareSum)/diff;
     
     int deleted= (diff+sums)/2;
     int added = sums - deleted;

     vector<int> result = {deleted,added};

    return  result;
}

int main()
{
    vector<int> a={1,2,4,5,2};
    vector<int> r = repeatedNumber(a);

    for( auto i : r)
    {
        cout<<i<<endl;
    }
    
}