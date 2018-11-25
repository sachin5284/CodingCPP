#include "Tree.h"
using namespace std;
int main()
{
    Tree t(20);
    t.AddNodes({10,15,16,30});
   // t.ReplaceNodeWithLowest(20);
    //t.Print();
    //t.PrintLeftSide();
    t.LevelOrderTraversal();
    // cout<<t.Diameter()<<endl;
}