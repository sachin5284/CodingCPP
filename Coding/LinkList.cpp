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

        void PrintList()
        {
            Node* temp = node;
            while(temp!=NULL)
            {
                cout<<temp->data<<endl;
                temp=temp->next;
            }
        }

        void AddNode(int val)
        {
            Node* temp= node;
            while(temp->next)
                temp=temp->next;
            temp->next = new Node(val);
        }

        bool DetectLoop()
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
        }


};


int main()
{
    LinkList l(10);
    l.AddNode(20);
    l.AddNode(30);
    l.AddNode(40);
    l.AddNode(50);
    l.PrintList();
    cout<<l.DetectLoop()<<endl;
    cout<<"Hello World"<<endl;
    return 0;
}