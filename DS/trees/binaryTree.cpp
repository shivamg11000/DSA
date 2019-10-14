// A tree whose elements have at most 2 children is called a binary tree

#include <iostream>
using namespace std;

float max(float a, float b){ return a>b?a:b;}  // helper fn

class Node{
    public: 
        int val;
        Node *left;
        Node *right;
        Node(int val){
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }
};

class Btree{        // Biary tree
    public:
        Node *root;
        Btree(){
            root = NULL;
        }
        void insert(int val){    // insert node into btree
            Node *node = new Node(val);
            if (root==NULL)        // if tree empty
                root = node;
            else 
                insert(root, node);
        } 
        // Inorder traversing procedure (Left, Root, Right)
        void inorderPrint(Node *node){   // fn call done on root
            if (node!=NULL) {   
                inorderPrint(node->left);
                cout<<node->val<<" ";
                inorderPrint(node->right);
            }
        }
        // PreOrder traversing procedure (Root, Left, Right)
        void preorderPrint(Node *node){
            if (node!=NULL) {   
                cout<<node->val<<" ";
                preorderPrint(node->left);
                preorderPrint(node->right);
            }
        }
        // Postorder (Left, Right, Root)
        void postorderPrint(Node *node){
            if (node!=NULL) {   
                postorderPrint(node->left);
                postorderPrint(node->right);
                cout<<node->val<<" ";
            }
        }
        int getHeight(Node *node){    // no of lvls + 1 = height , can be calculated by getting the longest path between root & leaf node
            if (node==NULL)
                return 0;
            return 1 + (int) max(getHeight(node->left), getHeight(node->right));    
        }
    private:
        void insert(Node* root, Node* node){

            // base cases    
            if (node->val < root->val && root->left==NULL)         
                root->left = node;
            else if (node->val >= root->val && root->right==NULL) 
                root->right = node;
            // recursive steps
            else if (node->val < root->val){   // lesser value to a node goes to the left
                insert(root->left, node);
            } else {                     // equal or greater goes to right
                insert(root->right, node);
            }   
        }
};

int main(void){
    Btree bt;
    int ar[] = {6, 5, 7, 4, 5, 6, 8};
    for (int i=0 ; i<sizeof(ar)/sizeof(ar[0]) ; i++)
        bt.insert(ar[i]);

    bt.inorderPrint(bt.root);
    cout<<endl;
    bt.preorderPrint(bt.root);
    cout<<endl;
    bt.postorderPrint(bt.root);
    cout<<endl;

    cout<<"height of a tree   :";
    cout<<bt.getHeight(bt.root);
    cout<<endl;

    cout<<"No of lvls in tree :";
    cout<<bt.getHeight(bt.root)-1;
    cout<<endl;

    return 0;
}