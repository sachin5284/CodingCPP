#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

class Tree
{
    node* root;
    public:
        Tree(int val)
        {
            this->root=new node(val);
        }
        Tree()
        {
            root = NULL;
        }

        int Diameter()
        {
            int height =0;
            return Diameter(root,&height);
        }
        void AddNodes(vector<int> val)
        {
            
            for(int i :val)
            {
                AddNode(i);
            }
            
            
        }       

        void AddNode(int val)
        {
            AddNode(val,&root); 
            
        }
         
        void Print()
        {
            Print(root);
        }

        void LevelOrderTraversal()
        {
            LevelOrderTraversal(root);
        }

        void ReplaceNodeWithLowest(int key)
        {
            ReplaceNodeWithLowest(root,key);
        }

        void PrintLeftSide()
        {
            PrintLeftSide(root);
        }
         

    private:
        void Print(node* t);
        int Diameter(node* root,int * height);
        void AddNode(int val,node** _root);
        void LevelOrderTraversal(node* root);
        void ReplaceNodeWithLowest(node * root,int key);
        void PrintLeftSide(node* root);

};

int Tree::Diameter(node* root,int* height)
{
    int leftHeight =0;
    int rightHeight = 0;

    if(root==NULL)
    {
        height=0;
        return 0;
    }

    int leftDiameter = Diameter(root->left,&leftHeight);
    int rightDiameter = Diameter(root->right,&rightHeight);

    *height = leftHeight+rightHeight+1;

    return max(*height,max(leftDiameter,rightDiameter));
}

void Tree::AddNode(int val,node** _root)
{
    if(root==NULL)
    {
    *_root=new node(val);
    return;
    }
    
    if((*_root)->data > val)
    {
        if((*_root)->left==NULL)
       { 
           (*_root)->left = new node(val);
            return;
        }
        else {
            AddNode(val,&(*_root)->left);
        }
    }
    else
    {
        if((*_root)->right==NULL)
        {
            (*_root)->right = new node(val);
            return;
        }
        else{
            AddNode(val,&(*_root)->right);
        }
    }
    
    
}

void Tree::Print(node* t)
{
    if(t==NULL)return;
    if(t->left)
    {
        Print(t->left);
    }
    cout<<t->data<<endl;
    Print(t->right);
}

void Tree::LevelOrderTraversal(node* root)
{
    queue<node*> q;
    if(root)
    {
        q.push(root);
    }

    while(!q.empty())
    {
        node* temp = q.front();
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }

        cout<<temp->data<<endl;
        q.pop();
    }
}

void Tree::ReplaceNodeWithLowest(node * root,int key)
{
    node* keyNode;
    queue<node*> q;
    node* temp;
    if(root)
    {
        q.push(root);
    }
    while(!q.empty())
    {
        temp = q.front();
        if(temp->data==key)
        {
            keyNode=temp;
        }
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
        q.pop();        
    }
    int x= temp->data;
    keyNode->data=x;

    node* d_node = temp;
    q.push(root);
    while(!q.empty()) 
    { 
        temp = q.front(); 
        q.pop(); 
  
        if (temp->right) 
        { 
            if (temp->right == d_node) 
            { 
                temp->right = NULL; 
                delete(d_node); 
                return; 
            } 
            else
                q.push(temp->right); 
        } 
  
        if (temp->left) 
        { 
            if (temp->left == d_node) 
            { 
                temp->left=NULL; 
                delete(d_node); 
                return; 
            } 
            else
                q.push(temp->left); 
        } 
    }
}

void Tree::PrintLeftSide(node* root)
{
    if(root)
    {
        cout<<root->data<<endl;
        if(root->left)
            PrintLeftSide(root->left);
        else
            PrintLeftSide(root->right);
    }
    return;
}