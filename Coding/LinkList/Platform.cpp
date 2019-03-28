#include<iostream>
#include<algorithm>

using namespace std;


struct Schedule
{
    int time;
    bool isArrival;

    bool operator>(const Schedule & a) const
    {
        return a.time<this->time;
    }

    bool operator<(const Schedule & a) const
    {
        return a.time>this->time;
    }
};

int GetMax(int arrival[],int departure[],int asize)
{
    const int  size = asize *2;
    Schedule *s= new Schedule[size];
    cout<<size<<endl;

    for(int i=0;i<asize;i++)
    {
        s[i]={arrival[i],true};
    }

    for(int i=0;i<asize;i++)
    {
        s[i+asize]={departure[i],false};
        
    }

    sort(s,s+size);

    int result = 0;
    int max=0;
    for(int i=0;i<size;i++)
    {
        cout<<s[i].time<<" "<<(s[i].isArrival)<<endl;
        if(s[i].isArrival)
        {
            result++;
            max= result>max?result:max;
        }
        else {
            result--;
        }
    }

    return max;
}

int main()
{
    int arr[] = {900, 940, 950, 1100, 1500, 1800}; 
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "Minimum Number of Platforms Required = " 
         << GetMax(arr, dep, n); 
}