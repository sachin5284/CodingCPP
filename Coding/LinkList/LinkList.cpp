#include "LinkList.h"

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