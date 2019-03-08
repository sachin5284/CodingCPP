#include<iostream>
#include<climits> 
using namespace std;

class MinHeap
{
    int *harr;
    int capacity;
    int heap_size;

    public:
        MinHeap(int capacity)
        {
            this->harr = new int[capacity];
            this->capacity = capacity;
            this->heap_size = 0;
            cout<<"Heap Created..!!"<<endl;
        }
        
        int GetParent(int n)
        {
            return this->harr[(n-1)/2];
        }

        int GetLeftChild(int n)
        {
            return this->harr[2*n+1];
        }

        int GetRightChild(int n)
        {
            return this->harr[2*n+1];
        }

        int GetMin()
        {
            return this->harr[0];
        }

        void InsertKey(int k);
        int ExtractMin();
        void Heapify(int p);

        void swap(int *a,int*b)
        {
            int temp = *a;
            *a =*b;
            *b=temp;
        }
};

void MinHeap::InsertKey(int k)
{
    if(heap_size==capacity)
        {
            cout<<"Heap OverFlowed.!!"<<endl;
            return;    
        }
    
    this->heap_size++;
    int i= heap_size-1;
    this->harr[i]=k;
    while(i!=0 && this->harr[this->GetParent(i)]>harr[i])
    {
        swap(&this->harr[this->GetParent(i)],&this->harr[i]);
        i=this->GetParent(i);
    }
    
    //cout<< k <<endl;
}

int MinHeap::ExtractMin()
{
    if (heap_size <= 0) 
        return INT_MAX; 

    if (heap_size == 1) 
    { 
        heap_size--; 
        return harr[0]; 
    } 

    int min = this->harr[0];
    this->harr[0] = this->harr[heap_size-1];
    heap_size--;
    this->Heapify(0);
    return min;
}
void MinHeap::Heapify(int p)
{
    if(heap_size==0)
    {
        return;
    }
     int lowestIndex = p;
     if(this->GetLeftChild(lowestIndex)<heap_size-1 && harr[lowestIndex]>harr[this->GetLeftChild(p)])
        lowestIndex = this->GetLeftChild(lowestIndex);

    if(this->GetRightChild(lowestIndex)<heap_size-1 && harr[lowestIndex]>harr[this->GetRightChild(p)])
        lowestIndex = this->GetLeftChild(lowestIndex);

    if(lowestIndex==p)
        return;
    
    swap(&this->harr[p],&this->harr[lowestIndex]);
    this->Heapify(lowestIndex);
}

int main()
{
    MinHeap h(2); 
    h.InsertKey(3); 
    h.InsertKey(2); 
    cout<<h.GetMin()<<endl;
    h.InsertKey(4); 
    cout<<h.ExtractMin()<<endl;
    cout<<h.ExtractMin()<<endl;
    cout<<h.ExtractMin()<<endl;
    cout<<h.ExtractMin()<<endl;
    return 0;
}