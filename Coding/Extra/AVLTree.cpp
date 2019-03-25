#include "AVLTree.h"


int main()
{
    AVLTree t(10);
    t.insert(2);
    t.insert(15);
    t.insert(22);
    t.insert(5);
    t.insert(6);
    t.insert(7);
    t.insert(8);
    t.printTree();
    t.deleteNode(15);
    cout<<endl;
    t.printTree();
    return 0;
}