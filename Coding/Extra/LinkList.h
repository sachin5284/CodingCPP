#include<iostream>
using namespace std;
struct Node
{
        int data;
        Node* next;

        Node(int val)
        {
            this->data=val;
            this->next=NULL;
        }
} ;



class LinkList
{
    private: 
        Node* root;
        Node* iterator;
    public:
        LinkList(int val)
        {
            root=new Node(val);
            iterator=root;
        }

        LinkList(initializer_list<int> list)
        {
            int n=sizeof(list)/sizeof(int);
            if(n>0)
            {
                int count=0;
                iterator=root;
                initializer_list<int> :: iterator i;
                 for ( i = list.begin(); i != list.end(); ++i) 
                 {
                     if(count==0){
                         root=new Node(*i);
                        iterator=root;
                     }
                     else{
                        iterator->next=new Node(*i);
                        iterator=iterator->next;
                     }
                     count++;
                 }
            }
        }


    public: void Addnode(int val)
    {
        iterator->next=new Node(val);
        iterator=iterator->next;
    }

    void PrintNode()
    {
        PrintNode(root);
    }
   private: void PrintNode(Node* next)
    {
        if(next)
        {
            cout<<next->data<<endl;
            PrintNode(next->next);
        }
    }

    public: void ReverseLinkList()
    {
        ReverseLinkList(&root);
    }

    private: void ReverseLinkList(Node** node)
    {
        if(node==NULL)return;
       Node* first=*node;
       Node* last=first->next;
       //cout<<last->data<<endl;
       if(last==NULL)return;
       ReverseLinkList(&last);
       first->next->next=first;
       first->next=NULL;
       //cout<<last->data<<endl;
       *node=last;
    }

};