#include <iostream>
#include "Graph.h"
 
using namespace std;
int main()
{

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
    // list<int> list1;
    // list1.push_back(1);
    // list<int> :: iterator it;
    // it=list1.begin();
    // cout<<*it<<endl;
    list<int> **list2 = new list<int> *[10];
    list2[0]=new list<int>();
    
    // list2[2]=new list<int>{1,2,3};
    // it=list2[2].begin();
    // cout<<*it<<endl;
}

