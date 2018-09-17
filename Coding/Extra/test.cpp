#include <queue>
#include <vector>
#include <iostream>
#include<queue>
 
using namespace std;

struct edge{
    int a;
    int b;
};

struct _comparer{
    bool operator()( edge a, edge b)
    {
        return a.a<b.a;
    }
};

int main() {
 priority_queue<edge,vector<edge>,_comparer> pq;
 pq.push({11,2});
 pq.push({2,3});
 pq.push({14,3});
 pq.push({1,4});
 pq.push({9,5});
 cout<<pq.top().b<<endl;
 
}