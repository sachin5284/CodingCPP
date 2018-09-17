#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val)
    {
        this->data=val;
        this->next=NULL;
    }
};
class LinkList{
    private:
        Node *root;
     public:
     LinkList(int val)
     {
         this->root=new Node(val);
     }

    void addNode(int val)
    {
        Node* iterator=root;
        while(iterator->next==NULL)iterator=iterator->next;
        iterator->next=new Node(val);
    }
    void PrintNode(Node* node)
    {
        while(node->next)   cout<<node->data<<" ";
    }
    void  reverseNode(Node** node)
    {
        Node* first=NULL,*temp=NULL;
        if(node!=NULL)Node* first=node;
        if(first->next!=NULL) temp=first->next;
        if(temp!=NULL && temp->next!=NULL)
        {
            reverseNode(&temp);
        }
        first->next->next=first;
        first->next=NULL;
        node=temp;
    }

    void reverseNode()
    {
        Node* result=reverseNode(root);

        PrintNode(result);
    }
    
};


int main()
{
    LinkList* list=new LinkList(1);
    list->addNode(2);
    list->addNode(3);
    list->addNode(4);
    list->addNode(5);
    list->addNode(6);
    list->reverseNode();
}