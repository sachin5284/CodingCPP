#include<iostream>
#include<math.h>
using namespace std;

class Segment_Tree
{
    private:
        int *arr;
        int size;
        int *st;
        int constructSegementTreeUtility(int ss,int se,int si);    
        void updateValueUtility(int ss,int se,int i,int diff,int si);
        int getSumUtility(int ss,int se,int qs,int qe,int si);

    public:
        Segment_Tree(int a[],int n)
        {
            this->arr=new int[n];
            for(int i=0;i<n;i++)arr[i]=a[i];
            this->size=n;
        }

        int getMid(int s, int e)
        {
            return s+(e-s)/2;
        }
        
        //Construct a Segment Tree
        void constructSegementTree();

        //Get sum of array from range qs to qe
        int getSum(int qs,int qe);

        //update value at i-th position to new_val
        void updateValue(int i, int new_val);
};


#pragma region Implementation

int Segment_Tree:: constructSegementTreeUtility(int ss,int se,int si)
        {

            //if there is only one element in segment tree
            if(ss==se)
            {
                st[si]=arr[ss];
                return arr[ss];
            }
            int mid=getMid(ss,se);
            st[si]=constructSegementTreeUtility(ss,mid,2*si+1) + constructSegementTreeUtility(mid+1,se,2*si+2);
            return st[si];
        }

void Segment_Tree :: updateValue(int i, int new_val)
{
    if(i<0 || i>size-1){
        cout<<"Invalid input"<<endl;
        return;
    }
    //check diff
    int diff=new_val-arr[i];

    updateValueUtility(0,size-1,i,diff,0);
}
void Segment_Tree :: updateValueUtility(int ss,int se,int i,int diff,int si)
        {
            if(i<ss || i>se)
                return;
            
            //if input i is within range add diff to st[si]
            st[si]=st[si]+diff;
            if(ss!=se)
            {
                int mid=getMid(ss,se);
                updateValueUtility(ss,mid,i,diff,2*si+1);
                updateValueUtility(mid+1,se,i,diff,2*si+2);
            }
        }

int Segment_Tree :: getSum(int qs,int qe)
        {
            //check out of range for qs and qe
            if(qs<0 || qe>size-1 || qs>qe)
            {
                cout<<"Invalid Input"<<endl;
                return -1;
            }
            return getSumUtility(0,size-1,qs,qe,0);
        }

int Segment_Tree:: getSumUtility(int ss,int se,int qs,int qe,int si)
        {
            //if segment of this node is a part of the given range
            if(qs<=ss && qe>=se)
                return st[si];
            
            if(se<qs || ss >qe)
                return 0;
            int mid=getMid(ss,se);
            return getSumUtility(ss,mid,qs,qe,2*si+1) + getSumUtility(mid+1,se,qs,qe,2*si+2);
        }
void Segment_Tree:: constructSegementTree()
        {
            //Height of segment tree
            int height=(int)(ceil(log2(size)));

            //Maximum size of Segment tree
            int max_size=2*(int)pow(2,height)-1;

            //Build segment Tree from a given array
            st=new int[max_size];
            constructSegementTreeUtility(0,size-1,0);
                      
        }     
  
#pragma endregion 