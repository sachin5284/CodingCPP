#include<iostream>
using namespace std;
struct node
{
    int key;
    node* left;
    node* right;
    int height;

    node(int val)
    {
        key=val;
        left=NULL;
        right=NULL;
        height=1;
    }
};

class AVLTree
{
    private:
        node* root;

        int height(node* n)
        {
            if(n!=NULL)  return n->height;
            return 0;
        }
        node* insert(node* _node,int key)
        {            
            if(_node==NULL)
            {
                return new node(key);
            }
            if(key < _node->key)
            {
                _node->left = insert(_node->left,key);
            }
            else if(key > _node->key)
                _node->right = insert(_node->right,key);
            else 
                return _node;
            
            _node->height=1+max(height(_node->left),height(_node->right));

            int balance=getBalance(_node);

            if(balance > 1)
            {
                if(key < _node->left->key)
                    return rightRotate(_node);
                else if(key > _node->left->key)
                {
                    _node->left=leftRotate(_node->left);
                    return rightRotate(_node);
                }
            }
            else if(balance < -1)
            {
                if(key > _node->right->key)
                    return leftRotate(_node);
                else if(key < _node->right->key)
                    {
                        _node->right==rightRotate(_node->left);
                        return leftRotate(_node);
                    }
            }

            return _node;
        }

        node* minValueNode(node* node)
        {
            auto _current = node;
        
            /* loop down to find the leftmost leaf */
            while (_current->left != NULL)
                _current = _current->left;
        
            return _current;
        }

        node* deleteNode(node* root, int key)
        {
            // STEP 1: PERFORM STANDARD BST DELETE
        
            if (root == NULL)
                return root;
        
            // If the key to be deleted is smaller than the
            // root's key, then it lies in left subtree
            if ( key < root->key )
                root->left = deleteNode(root->left, key);
        
            // If the key to be deleted is greater than the
            // root's key, then it lies in right subtree
            else if( key > root->key )
                root->right = deleteNode(root->right, key);
        
            // if key is same as root's key, then This is
            // the node to be deleted
            else
            {
                // node with only one child or no child
                if( (root->left == NULL) || (root->right == NULL) )
                {
                    node *temp = root->left ? root->left :
                                                    root->right;
        
                    // No child case
                    if (temp == NULL)
                    {
                        temp = root;
                        root = NULL;
                    }
                    else // One child case
                    *root = *temp; // Copy the contents of
                                    // the non-empty child
                    free(temp);
                }
                else
                {
                    // node with two children: Get the inorder
                    // successor (smallest in the right subtree)
                    node* temp = minValueNode(root->right);
        
                    // Copy the inorder successor's data to this node
                    root->key = temp->key;
        
                    // Delete the inorder successor
                    root->right = deleteNode(root->right, temp->key);
                }
            }
        
            // If the tree had only one node then return
            if (root == NULL)
            return root;
        
            // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
            root->height = 1 + max(height(root->left),
                                height(root->right));
        
            // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
            // check whether this node became unbalanced)
            int balance = getBalance(root);
        
            // If this node becomes unbalanced, then there are 4 cases
        
            // Left Left Case
            if (balance > 1 && getBalance(root->left) >= 0)
                return rightRotate(root);
        
            // Left Right Case
            if (balance > 1 && getBalance(root->left) < 0)
            {
                root->left =  leftRotate(root->left);
                return rightRotate(root);
            }
        
            // Right Right Case
            if (balance < -1 && getBalance(root->right) <= 0)
                return leftRotate(root);
        
            // Right Left Case
            if (balance < -1 && getBalance(root->right) > 0)
            {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        
            return root;
        }
        
    public:
        AVLTree(int val)
        {
            root=new node(val);
        }
     
        node* rightRotate(node* y)
        {
            node* x=y->left;
            node* T2=x->right;

            x->right=y;
            y->left=T2;

            y->height=max(height(y->left),height(y->right))+1;
            x->height=max(height(x->left),height(x->right))+1;
            return x;
        }

        node* leftRotate(node* x)
        {
            node* y=x->right;
            node* T2=y->left;

            y->left=x;
            x->right=T2;

            x->height=max(height(x->left),height(x->right))+1;
            y->height=max(height(y->left),height(y->right))+1;
        }
        
        int getBalance(node* n)
        {
            if(n!=NULL)return height(n->left)-height(n->right);
            return 0;
        }

        void insert(int val)
        {
            this->root=insert(this->root,val);
        }
        void deleteNode(int key)
        {
            if(this->root!=NULL)this->root=deleteNode(this->root,key);
        }
        void printTree(node* n)
        {
            if(n==NULL)return;
            cout<<n->key<<" ";
            printTree(n->left);
            printTree(n->right);
        }

        void printTree()
        {
            printTree(this->root);
        }


};


int main()
{
    AVLTree t(10);
    t.insert(2);
    t.insert(15);
    t.insert(22);
    t.insert(5);
    t.insert(6);
    t.insert(7);
    t.insert(8);
    t.printTree();
    t.deleteNode(15);
    cout<<endl;
    t.printTree();
    return 0;
}