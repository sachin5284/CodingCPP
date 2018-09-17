#include "Tree.h"
using namespace std;
int main()
{
    Tree t;
    t.AddNode(20);
    t.AddNode(5);
    t.AddNode(30);
    t.ReplaceNodeWithLowest(20);
    t.Print();
    // t.LevelOrderTraversal();
    // cout<<t.Diameter()<<endl;
}