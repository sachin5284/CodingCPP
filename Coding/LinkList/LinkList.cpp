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
    //l.MakeLoop();

    LinkList* l2=l.ReverseList();
    l2->PrintList();
    // cs// cout<<l.FindLoopLength();
    return 0;
}