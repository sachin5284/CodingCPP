#include "Tree.h"
using namespace std;
int main()
{
    Tree t(20);
    t.AddNode(10);
    t.AddNode(15);
    t.AddNode(16);
    t.AddNode(30);
   // t.ReplaceNodeWithLowest(20);
    //t.Print();
    t.PrintLeftSide();
    // t.LevelOrderTraversal();
    // cout<<t.Diameter()<<endl;
}