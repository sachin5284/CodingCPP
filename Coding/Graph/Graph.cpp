#include<iostream>
#include<list>
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

        void addNode(int node,int edge)
        {
            this->adj[node].push_back(edge);
        }

        void printGraph()
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
};
int main()
{
    Graph g(10);
    g.addNode(1,7);
    g.addNode(4,8);
    g.printGraph();
    //cout<<"HellO World..!!"<<endl;
}