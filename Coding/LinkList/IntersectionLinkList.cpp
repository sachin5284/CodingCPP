#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next =NULL;
    }
};

Node* GetIntersection(Node * first,Node* second)
{
    if(first==NULL || second ==NULL)
    {
        return NULL;
    }

    if(first->data > second->data)
    {
        return GetIntersection(first,second->next);
    }

    if(first->data < second->data)
    {
        return GetIntersection(first->next,second);
    }

    Node* temp = new Node(first->data);
    temp->next = GetIntersection(first->next,second->next);

    return temp;
}

Node* GetNode(int a[],int size)
{
    if(size==0)
    {
        return NULL;
    }
    Node* temp1= new Node(a[0]);
    Node* temp2=temp1;
    for(int i=1;i<size;i++)
    {
        temp2->next = new Node(a[i]);
        temp2 = temp2->next;
    }
    return temp1;
}

int main()
{
    int first[] ={1,2,3,4,5};
    int second[] ={2,4};
    Node* intersection = GetIntersection(GetNode(first,5),GetNode(second,3));

    while(intersection)
    {
        cout<<intersection->data<<endl;
        intersection = intersection->next;
    }
}