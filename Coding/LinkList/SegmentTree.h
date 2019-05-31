#include<iostream>
#include<math.h>

using namespace std;

class SegmentTree
{
    int *arr;
    int size;
    int* segmentTreeArr;
    int segmentTreeSize;
    int createSegmentTree(int start,int end, int index);
    void updateSegmentTree(int start,int end,int diff,int index,int updateIndex);
    int getSum(int start,int end,int qstart,int qend,int index);

    public:
        SegmentTree(int array[],int size)
        {
            this->size = size;
            arr = new int[this->size];
            for(int i=0;i<this->size;i++)
            {
                this->arr[i] = array[i];
            }
        }
        void createSegmentTree();
        void updateSegmentTree(int index,int val);
        int getSum(int qstart,int qend);
        void printSegmentTree();
};

void SegmentTree::createSegmentTree()
{
    int height = ceil(log2(this->size));
    this->segmentTreeSize = 2*((int)pow(2,height))-1;
    this->segmentTreeArr = new int[segmentTreeSize];
    for(int i=0;i<segmentTreeSize;i++)
        this->segmentTreeArr[i]=0;
        
    this->createSegmentTree(0,size-1,0);
}

int SegmentTree :: createSegmentTree(int start,int end,int index)
{
    if(start == end)
    {
        segmentTreeArr[index] = arr[start];
        return arr[start];
    }
        int mid = start + (end-start)/2;
        segmentTreeArr[index] = this->createSegmentTree(start,mid,index*2+1) + 
                            this->createSegmentTree(mid+1,end,2*index+2);
           
    return segmentTreeArr[index];
}

void SegmentTree :: printSegmentTree()
{
    for(int i=0;i<segmentTreeSize;i++)
    {
        cout<<segmentTreeArr[i]<<" ";
    }
    cout<<endl;
}

void SegmentTree :: updateSegmentTree(int index,int val)
{
    if(index < 0 ||  index >= this->size)
        return;
    
    int diff = val - arr[index];
    arr[index] = val;
    updateSegmentTree(0,this->size-1,diff,0,index);
}

void SegmentTree :: updateSegmentTree(int start,int end,int diff,int index,int updateIndex)
{
    if(updateIndex<start || updateIndex>end)
        return;
    
    segmentTreeArr[index] += diff;

    if(start == end)return;
    int mid = start + (end-start)/2;
    updateSegmentTree(start,mid,diff,2*index+1,updateIndex);
    updateSegmentTree(mid+1,end,diff,2*index+2,updateIndex);
}

int SegmentTree :: getSum(int qstart,int qend)
{
    return getSum(1,this->size-1,qstart,qend,0);
}

int SegmentTree :: getSum(int start,int end,int qstart,int qend,int index)
{
    if(qstart <= start && qend >= end)
    {
        return segmentTreeArr[index];
    }

    if(qstart > end || qend < start)
    {
        return 0;
    }
    int mid = start +(end-start)/2;
    return getSum(start,mid,qstart,qend,2*index+1)+
            getSum(mid+1,end,qstart,qend,2*index+2);
}