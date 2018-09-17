#include <bits/stdc++.h>
using namespace std;


void heapify(vector<int> &arr,int i,int n){
  int a=arr[i],b=0,c=0,large;
        if((2*i)+1<n)
        b=arr[(2*i)+1];
        if((2*i)+2<n)
        c=arr[(2*i)+2];
        if(b>c)
        large=(2*i)+1;
        else
        large=(2*i)+2;
        if(arr[large]>arr[i]){
            arr[i]=arr[large];
            arr[large]=a;
            heapify(arr,large,n);
        }  
}

void buildheap(vector<int> &arr,int n){
    if(n==0||n==1)
    return;
    for(int i=(n/2)-1;i>=0;i--)
    {
        int a=arr[i],b=0,c=0,large;

        if((2*i)+1<n)
            b=arr[(2*i)+1];
        if((2*i)+2<n)
            c=arr[(2*i)+2];
        if(b>c)
            large=(2*i)+1;
        else
            large=(2*i)+2;
            
        if(arr[large]>arr[i])
        {
            arr[i]=arr[large];
            arr[large]=a;
            heapify(arr,large,n);
        }
    }
}



int main() {
		int n;
	    cin>>n;
        vector<int> vec;
        for(int i=0;i<n;i++)
        {
            int num;
            cin>>num;
            vec.push_back(num);
            for(int j=vec.size()-1;j>=1;j--)
            {
                buildheap(vec,j+1);
                int b=vec[0];
                vec[0]=vec[j];
                vec[j]=b;
            }
            for(int j=0;j<=vec.size()-1;j++)
                cout<<vec[j]<<" ";
            cout<<endl;
        }
        return 0;
}