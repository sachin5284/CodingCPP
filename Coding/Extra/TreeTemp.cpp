#include<iostream>
using namespace std;

struct tree
{
    int data;
    tree* left;
    tree* right;

    tree(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

struct node
{
    int data;
    node* next;

    node(int val)
    {
        data=val;
        next=NULL;
    }
};

pair<node*,node*> splitMidNode(node* _node)
{
    if(_node->next==NULL) return {NULL,NULL};
    node* root=_node;
    node* first=_node;
    node* second=_node;
    node* temp=first;
    while(second!=NULL && second->next!=NULL)
    {
        temp=first;
        first=first->next;
        second=second->next->next;
    }
    
    pair<node*,node*> p;
    p.second=temp->next->next;
    temp->next=NULL;
    p.first=root;
    return p;

}

tree* getMidNode(node* _node)
{
    if(_node==NULL)return NULL;
    node* first=_node;
    node* second=_node;
    while(second!=NULL && second->next!=NULL)
    {
        first=first->next;
        second=second->next->next;
    }
    tree* result=new tree(first->data);
    return result;

}

void AddNode(node** _node,int val)
{
    node* list= *_node;
    while((list->next!=NULL))list=list->next;
    list->next=new node(val);

}
void printNode(node* node)
{
    while(node!=NULL)
    {
        cout<<node->data<< " ";
        node=node->next;
    }
}

tree* makeBST(node* list)
{
    if(list==NULL)return NULL;
    tree* result=getMidNode(list);
    if(list->next==NULL)return result;
    //cout<<result->data<<endl;
    pair<node*,node*> p=splitMidNode(list);
    
    result->left=makeBST(p.first);
    result->right=makeBST(p.second);
    return result;
}

void printTree(tree* root)
{
    if(root==NULL)return;
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    node* list=new node(1);
    AddNode(&list,2);
    AddNode(&list,3);
    AddNode(&list,4);
    AddNode(&list,5);
    AddNode(&list,6);
    
    tree* t=makeBST(list);
    printTree(t);
    return 0;
}