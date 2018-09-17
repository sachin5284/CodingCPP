// C++ program for above implementation
#include <iostream>
#include "Segment_Tree.h"
#include<unordered_map>
// #include<list>
// #define MOD 1000000007
using namespace std;

// Driver code
int main()
{
    int a[]={1,2,4,4,5,6,7,8,98};
    Segment_Tree t(a,sizeof(a)/sizeof(int));
    t.constructSegementTree();
    cout<<t.getSum(2,4);

    return 0;
}
