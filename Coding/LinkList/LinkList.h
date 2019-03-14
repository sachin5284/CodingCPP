#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

class LinkList
{
    Node* node;
    public:
        LinkList(int val)
        {
            this->node = new Node(val);
        }
        LinkList(Node* copyNode)
        {
            this->node= copyNode;
        }

        void PrintList()
        {
            Node* temp = node;
            while(temp!=NULL)
            {
                cout<<temp->data<<endl;
                temp=temp->next;
            }
        }

        LinkList* ReverseList()
        {
            Node* temp = node;
            ReverseNode(&temp);
            return new LinkList(temp);
            
        }
        
        void ReverseNode(Node** head)
        {
            Node* first = *head;
            if(first==NULL)return;
            Node* rest = first->next;

            if(rest==NULL)return;

            ReverseNode(&rest);
            first->next->next=first;
            first->next=NULL;
            *head=rest;

        }

        void AddNode(int val)
        {
            Node* temp= node;
            while(temp->next)
                temp=temp->next;
            temp->next = new Node(val);
        }

        bool DetectLoop();
        int FindLoopLength();
        void MakeLoop();

        


};


bool LinkList :: DetectLoop()
    {
        Node* fast = node;
        Node* slow = node;
        while(fast && slow && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
            {
                return true;
            }
        }
        return false;
    };

int LinkList:: FindLoopLength()
{
    Node* fast = node;
        Node* slow = node;
        while(fast && slow && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
            {
                int count=1;
                Node* temp=slow;
                while(temp->next!=slow)
                {
                    count++;
                    temp=temp->next;
                }
                return count;
            }
        }
        return 0;
};

void LinkList:: MakeLoop()
{
    Node* temp = node;
    while(temp->next)
        temp=temp->next;
    temp->next=node->next;
};