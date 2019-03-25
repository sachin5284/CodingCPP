#include"SegmentTree.h"

using namespace std;


int main()
{
    int a[]={1, 3, 5, 7, 9, 11};
    int size = sizeof(a)/sizeof(int);
    SegmentTree s(a,size);
    s.createSegmentTree();
    s.printSegmentTree();
    s.updateSegmentTree(2,6);
    cout<<s.getSum(0,3)<<endl;
    return 0;
}