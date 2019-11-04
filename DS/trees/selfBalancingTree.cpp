// A tree whose elements have at most 2 children is called a binary tree
// A binary tree whoes left subtree containes lesser value & right subtree contain greater or equal values is called a binary search tree

// https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
// https://www.youtube.com/watch?v=jDM6_TnYIqE

// https://www.geeksforgeeks.org/self-balancing-binary-search-trees-comparisons/

#include <iostream>
#include <queue>
using namespace std;

float max(float a, float b){ return a>b?a:b;}  // helper fn

class Node{
    public: 
        int key;
        Node *left;
        Node *right;
        int height;   // height of a subtree with node as root
        Node(int key){
            this->key = key;
            this->left = NULL;
            this->right = NULL;
            this->height = 1;  // new node is inserted as leaf node where h=1
        }
};

void lvlOrderPrint(Node *root){  
    queue<Node *> q;
    q.push(root);
    Node *cur = NULL;
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        if (cur->left!=NULL)
            q.push(cur->left);
        if (cur->right!=NULL)
            q.push(cur->right);    
        cout<<cur->key<<" ";    
    }
    cout<<endl;
}
void inOrderPrint(Node *root){
    if (root==NULL)
        return;
    inOrderPrint(root->left);
    cout<<root->key<<" ";
    inOrderPrint(root->right);
}

class AVLTree{        // Self Balancing Binary Search tree - AVL Tree
    public:
        Node *root;
        AVLTree(){
            root = NULL;
        }  
        Node *rightRotate(Node *y){  // rotate subtree rooted with y   
            Node *x = y->left;  
            Node *T2 = x->right;  
            // Perform rotation  
            x->right = y;  
            y->left = T2;  
            // Update heights  
            y->height = max(getHeight(y->left), 
                            getHeight(y->right)) + 1;  
            x->height = max(getHeight(x->left), 
                            getHeight(x->right)) + 1;  
            // Return new root  
            return x;  
        }    
        Node *leftRotate(Node *x){  // rotate subtree rooted with x
            Node *y = x->right;  
            Node *T2 = y->left;  
            // Perform rotation  
            y->left = x;  
            x->right = T2;  
            // Update heights  
            x->height = max(getHeight(x->left),     
                            getHeight(x->right)) + 1;  
            y->height = max(getHeight(y->left),  
                            getHeight(y->right)) + 1;  
            // Return new root  
            return y;  
        }
        // inserts key into tree in similar way to bst & performs rotations necessary & return the root 
        Node* insert(Node* root, int key){  
            /* 1. Perform the normal BST insertion */
            if (root == NULL)  
                return(new Node(key));  
        
            if (key < root->key)  
                root->left = insert(root->left, key);  
            else if (key > root->key)  
                root->right = insert(root->right, key);  
            else // Equal keys are not allowed in BST  
                return root;  

            // backtrack up the tree
            /* 2. Update height of this ancestor nodes */
            root->height = 1 + (int) max(getHeight(root->left),  
                                   getHeight(root->right));  
        
            /* 3. Get the balance factor of this ancestor  
                node to check whether this node became  
                unbalanced */
            int bf = getBalanceFactor(root);  
        
            // If this node becomes unbalanced, then  
            // there are 4 cases  
        
            // Left Left Case  
            if (bf > 1 && key < root->left->key)  
                return rightRotate(root); 
            // Right Right Case  
            if (bf < -1 && key > root->right->key)  
                return leftRotate(root);  
            // Left Right Case  
            if (bf > 1 && key > root->left->key){  
                root->left = leftRotate(root->left);  
                return rightRotate(root);  
            }  
            // Right Left Case  
            if (bf < -1 && key < root->right->key){  
                root->right = rightRotate(root->right);  
                return leftRotate(root);  
            }  
        
            /* return the (unchanged) node pointer */
            return root;  
        }

        int getHeight(Node *root){    // height of tree 
            if (root == NULL)
                return 0;
            return root->height;   
        }
        // Get Balance factor of node N  
        int getBalanceFactor(Node *N){  // should be in {-1,0,1} for a node else the subtree with node as root is not balanced
            if (N == NULL)  
                return 0;  
            return getHeight(N->left) - getHeight(N->right);  
        }
};

int main(void){
    AVLTree avl;
    int ar[] = {6, 7, 4, 5, 10, 8, 1, 20, 3, 9};
    for (int i=0 ; i<sizeof(ar)/sizeof(ar[0]) ; i++)
        avl.root = avl.insert(avl.root, ar[i]);

    // after insertion, avl tree will look like
    /*
                 6
             /       \
            4         8
          /   \     /    \
         1     5    7     10
          \              /  \
           3            9    20
    */
    lvlOrderPrint(avl.root);
    inOrderPrint(avl.root);
    cout<<endl;
    return 0;
}