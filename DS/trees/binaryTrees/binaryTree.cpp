// A tree whose elements have at most 2 children is called a binary tree
// preorder, inorder, postorder traversals comes in dfs
// level order traverseal come in bfs

#include <iostream>
#include <queue>
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

class Btree{        // Binary tree
    public:
        Node *root;
        Btree(){
            root = NULL;
        }
        // insertion can be done in any way in binary tree, its not a bst, but insertion in level order will make it complete binary tree
        void insert(int val){    // insert node into btree
            Node *node = new Node(val);
            if (this->root==NULL) {       // if tree empty
                this->root = node;
                return;
            }
            queue<Node *> q;
            q.push(this->root);
            while(!q.empty()) {  // traverse tee in lvl order until found first node with left or right NULL
                Node *cur = q.front();
                if (cur->left==NULL){
                    cur->left = node;
                    break;
                }
                else if(cur->right==NULL){
                    cur->right = node;
                    break;    
                }
                q.pop();
                if (cur->left!=NULL)
                    q.push(cur->left);
                if (cur->right!=NULL)
                    q.push(cur->right);        
            }    
        } 
        // all dfs takes O(n)
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
        void bfsPrint(Node *node){   // here node is root, O(n)
            queue<Node *> q;

            q.push(node);
            while(!q.empty()){
                Node *cur = q.front();
                q.pop();
                cout<<cur->val<<" ";
                if (cur->left != NULL)
                    q.push(cur->left);
                if (cur->right != NULL)
                    q.push(cur->right);        
            }
            cout<<endl;
        }
        int getHeight(Node *node){    // no of lvls + 1 = height , can be calculated by getting the longest path between root & leaf node
            if (node==NULL)
                return 0;
            return 1 + (int) max(getHeight(node->left), getHeight(node->right));    
        }
        void search(int key){    // traverse in lvl order & search a node by its value/key, O(n)
           if (this->root==NULL)        // if tree empty
                return;
            queue<Node *> q;
            q.push(this->root);
            while(!q.empty()) {      // traverse tee in lvl order until found first matching node 
                Node *cur = q.front();
                q.pop();
                if (cur->val == key){
                    cout<<key<<" exists\n";
                    return;  
                }
                if (cur->left!=NULL)
                    q.push(cur->left);
                if (cur->right!=NULL)
                    q.push(cur->right);        
            }    
            cout<<key<<" does not exist\n";
        }
};

int main(void){
    Btree bt;
    int ar[] = {6, 5, 7, 4, 5, 6, 8};
    for (int i=0 ; i<sizeof(ar)/sizeof(ar[0]) ; i++)
        bt.insert(ar[i]);

    // dfs
    cout<<"dfs\n";
    bt.inorderPrint(bt.root);
    cout<<endl;
    bt.preorderPrint(bt.root);
    cout<<endl;
    bt.postorderPrint(bt.root);
    cout<<endl;

    // bfs
    cout<<"bfs\n";
    bt.bfsPrint(bt.root);

    cout<<"height of a tree   :";
    cout<<bt.getHeight(bt.root);
    cout<<endl;

    cout<<"No of lvls in tree :";
    cout<<bt.getHeight(bt.root)-1;
    cout<<endl;

    bt.search(7);

    return 0;
}