#include<iostream>

using namespace std;

int findWaterStore(int a[],int size)
{
    int low =0,high=size-1,low_max=0,high_max=0,result=0;

    while(low < high)
    {
        if(a[low] < a[high]){
            if(low_max<a[low]){
                low_max=a[low];
            }
            else{
                result += low_max - a[low];
            }
            low++;
        }
        else{
           if(high_max<a[high]){
                high_max = a[high];
            }
            else{
                result += high_max - a[high];
            }
            high--; 
        }
    }
    return result;
}
int main()
{
    int a[]={0,1,0,2,1,0,1,3,2,1,2,1};
    int size = sizeof(a)/sizeof(int);

    cout<<findWaterStore(a,size)<<endl;
}