#include<iostream>

using namespace std;
void transposeArray(int** arr,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=i;j<size;j++)
        {
            swap(arr[i][j],arr[j][i]);
        }
    }
}

int main()
{
    int **arr = new int*[4];
    for(int i=0;i<4;i++)
    {
        arr[i]= new int[4]{4*i+1, 4*i+2,4*i+3,4*i+4};
    }
    transposeArray(arr,4);
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
        }
    return 0;
}