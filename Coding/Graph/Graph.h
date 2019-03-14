#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
using namespace std;

class Graph
{
    private:
        int node;
        list<int> *adj;
    
    public:
        Graph(int node)
        {
            this->node=node;
            this->adj = new list<int>[node];
            
        }

        void addEdge(int v, int w);
        void BFS(int s);
        void DFS(int s);
        void DFSUtility(int s,vector<bool> &visited);
        void TopologicalSort();
        void TopologicalSortUtility(int v,vector<bool> &visited,stack<int> &s);
        void printGraph();
};

void Graph :: addEdge(int v,int w)
{
    adj[v].push_back(w);
}

void Graph :: BFS(int s)
{
    vector<bool> visited(this->node,false);
    queue<int> q;

    q.push(s);

    list<int> :: iterator it;
    while(!q.empty())
    {
        s= q.front();

        cout<<s<<" ";
        q.pop();

        for(it=adj[s].begin();it!=adj[s].end();++it)
        {
            if(!visited[*it])
            {
                visited[*it] = true;
                q.push(*it);
            }
        }
    }
}

void Graph  :: printGraph()
{
    for(auto i=0;i<this->node;i++)
    {
        cout<<i<<endl;
        for(auto j:this->adj[i])
        {
            cout<<" "<<j;
        }
        cout<<endl;
    }
}

void Graph :: DFS(int s)
{
    vector<bool> visited(this->node,false);
    DFSUtility(s,visited);
}

void Graph :: DFSUtility(int s, vector<bool> &visited)
{
    if(visited[s])
        return;
    visited[s]=true;
    cout<<s<<" ";

    list<int> :: iterator it;

    for(it=adj[s].begin();it!=adj[s].end();++it)
    {
        if(!visited[*it])
        {
            DFSUtility(*it,visited);
        }
    } 

}

void Graph :: TopologicalSort()
{
    vector<bool> visited(this->node,false);

    list<int> :: iterator it;
    stack<int> topologicalList;
    
    for(int i=0;i<this->node;i++)
    {
        if(!visited[i])
        {
            TopologicalSortUtility(i,visited,topologicalList);
        }
    }
    cout<<"TopologicalSort is:- ";
    while(!topologicalList.empty())
    {
        cout<<topologicalList.top()<<" ";
        topologicalList.pop();
    }
}

void Graph:: TopologicalSortUtility(int v,vector<bool> &visited,stack<int> &s)
{
    visited[v]=true;

    list<int> :: iterator it;

    for(it=adj[v].begin();it!=adj[v].end();++it)
    {
        if(!visited[*it])
        {
            TopologicalSortUtility(*it,visited,s);
        }
    }
    s.push(v);
}

