#include<iostream>
#include<stack>
#include<unordered_set>


using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int key)
    {
        this->data = key;
        this->left=NULL;
        this->right=NULL;
    }
};

class Tree
{
    Node* treeNode=NULL;

    public:
        void AddNode(int key)
        {
            if(treeNode==NULL)
            {
                treeNode = new Node(key);
                return;
            }
            AddNode(treeNode,key);
        }

        void AddNode(Node* root,int key)
        {
            if(key<root->data)
            {
                if(root->left)
                {
                    AddNode(root->left,key);
                }
                else
                {
                    root->left=new Node(key);
                    return;
                }
                
            }
            else
            {
                if(root->right)
                {
                    AddNode(root->right,key);
                }
                else
                {
                    root->right=new Node(key);
                    return;
                }
                
            }
        }

        void AddArray(int a[],int size)
        {
            for(int i=0;i<size;i++)
            {
                AddNode(a[i]);
            }
        }


        void InorderTarversal()
        {
            Node* current = this->treeNode;

            stack<Node*> s;

            while(!s.empty() || current!=NULL)
            {
                while(current!=NULL)
                {
                    s.push(current);
                    current=current->left;
                }

                Node* temp = s.top();
                s.pop();

                cout<<temp->data<<endl;

                current=temp->right;
            }
        }
};




int main()
{
    Tree t;
    int a[] ={1,5,6,2,3,7};
    int size= sizeof(a)/sizeof(a[0]);
    t.AddArray(a,size);
    t.InorderTarversal();
    unordered_set<int> s={1,1,2,1,1,2,3,4};

    for(auto it:s)
    {
        cout<<it<<endl;
    }
    if(s.find(3)!=s.end())
    {
        cout<<"Found"<<endl;
    }
}