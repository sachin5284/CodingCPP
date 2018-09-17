#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<list>
#include<stack>
#include<queue>
using namespace std;
struct Edge
{
    int V;
    int E;
    int distance;
};
class Graph
{
    private:
        int V;
        list<int> *adj;
        int **dis;
        vector<Edge> edge;
                
        void DFSUtility(int v,bool visited[]);
        void TopologicalSortUtility(bool Visited[]);
        void allTopologicalSortsUtility(vector<int> &res,vector<int> indegree,vector<bool> visited);
        int FindParent(vector<int> relatives,int i);
        void Union(vector<int> &relatives,int x,int y);
        bool UnionFindUtility(vector<int>relatives,vector<Edge> eg);

    public:
    Graph(int v)
    {
        this->V=v;
        adj=new list<int> [v];
        this->dis=new int*[v];
        for(int i=0;i<v;i++)this->dis[i]=new int[v];
    }

    void addEdge(int v,int e,int distance=-1)
    {
        adj[v].push_back(e);
        edge.push_back({v,e,distance});
        this->dis[v][e]=distance;
    }

    void BFS(int s);
    void DFS(int v);
    void TopologicalSort();
    void allTopologicalSorts();
    void UnionFind();
    void MinimumSpaningTree();
    void primeMinimumSpaningTree(int i);

};

#pragma region Implementation
void Graph:: BFS(int s)
    {
        bool *visited = new bool[V];
        for(int i = 0; i < V; i++)
            visited[i] = false;
    
        list<int> queue;
    
        visited[s] = true;
        queue.push_back(s);
    
    
        while(!queue.empty())
        {
            s = queue.front();
            cout << s << " ";
            queue.pop_front();
    
            for (auto i : adj[s])
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    queue.push_back(i);
                }
            }
        }
    }

void Graph::DFS(int v)
{
    bool visited[this->V];
    for(int i=0;i<this->V;i++)visited[i]=false;
    DFSUtility(v,visited);
}

void Graph :: DFSUtility(int v,bool visited[])
{
    if(visited[v]==true)return;
    visited[v]=true;
    cout<<v<<" ";

    for(auto it:adj[v])
    {
        if(!visited[it])
        {
            DFSUtility(it,visited);
        }
    }

}

void Graph :: TopologicalSort()
{
    bool visited[this->V];
    for(int i=0;i<this->V;i++)visited[i]=false;
    TopologicalSortUtility(visited);
}

void Graph :: TopologicalSortUtility(bool visited[])
{
    stack<int> st;
    for(int i=0;i<this->V;i++)
    {
        stack<int> temp;
        if(!visited[i])
        {
            visited[i]=true;
            temp.push(i);
            for(auto it=adj[i].begin();it!=adj[i].end();++it)
            {
                if(!visited[*it])
                {
                    visited[*it]=true;
                    temp.push(*it);
                }
            }
        }
        while(!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
    }

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }

}
void Graph :: allTopologicalSorts()
{
    vector<int> res;
    vector<int> indegree(this->V,0);
    vector<bool> visited(this->V,false);
    allTopologicalSortsUtility(res,indegree,visited);

}

void Graph :: allTopologicalSortsUtility(vector<int> &res,vector<int> indegree,vector<bool> visited)
{
    bool flag=false;

    for(int i=0;i<this->V;i++){
        if(indegree[i]==0 && !visited[i])
        {
            
            for(auto it=adj[i].begin();it!=adj[i].end();++it)
            {
                indegree[*it]++;
            }
            res.push_back(i);
            visited[i]=true;
            allTopologicalSortsUtility(res,indegree,visited);

            for(auto it=adj[i].begin();it!=adj[i].end();++it)
            {
                indegree[*it]--;
            }
            res.pop_back();
            visited[i]=true;
            flag=true;
        }
    }
    if(!flag)
    {
        for(int i:res)
        {
            cout<<i<<" "<<endl;
        }
    }
}
int Graph::FindParent(vector<int> relatives,int i)
{
    if(relatives[i]==-1)return i;
    return FindParent(relatives,relatives[i]);
}

void Graph  :: Union(vector<int> &relatives,int x,int y)
{
    relatives[x]=y;
}
bool Graph:: UnionFindUtility(vector<int>relatives,vector<Edge> eg)
{
    for(Edge i:eg)
    {
        int x=FindParent(relatives,i.E);
        int y=FindParent(relatives,i.V);
        if(x==y)
        {
            
            return true;
        }
        else Union(relatives,x,y);
    }
    return false;
}

void Graph:: UnionFind()
{
    vector<int> relatives(this->V,-1);
    if(UnionFindUtility(relatives,this->edge))cout<<"Cycle detected"<<endl;
}


void Graph:: MinimumSpaningTree()
{
    sort(this->edge.begin(),this->edge.end(),[](Edge a, Edge b){return a.distance<b.distance;});

    vector<int> relatives(this->V,-1);
    vector<Edge> redge;
    for(Edge e:this->edge)
    {
        redge.push_back(e);
        if(UnionFindUtility(relatives,redge))redge.pop_back();
    }
    cout<<"Minimum Spanning Tree: "<<endl;
    for(Edge eg:redge)
    {
        cout<<eg.V<<" "<<eg.E<<" "<<eg.distance<<endl;
    }
}

struct _comparer
{
    bool operator()(const Edge& a,const Edge& b)const
    {
        return a.distance>b.distance;
    }
};
void Graph :: primeMinimumSpaningTree(int i)
{
    //Todo: Remember this
    auto comp = [] (Edge &a, Edge &b) -> bool { return a.distance > b.distance; };
    priority_queue<Edge,vector<Edge>,_comparer> pq;
    vector<bool> visited(this->V,false);
    vector<Edge> result;

    for(auto k:adj[i])
    {
        pq.push({i,k,this->dis[i][k]});
    }
    visited[i]=true;
    while(!pq.empty())
    {
        Edge eg=pq.top();
        pq.pop();
        if(visited[eg.E])return;
        visited[eg.E]=true;
        result.push_back(eg);

        for(auto j:adj[eg.E])
        {
            if(!visited[j])
                pq.push({eg.V,j,this->dis[eg.V][j]});
        }
    }

    for(auto e:result)
        cout<<e.V<<" "<<e.E<<" "<<e.distance<<endl;

}
#pragma endregion