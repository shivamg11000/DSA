// A tree whose elements have at most 2 children is called a binary tree
// A binary tree whoes left subtree containes lesser value & right subtree contain greater or equal values is called a binary search tree


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

class BST{        // Binary Search tree
    public:
        Node *root;
        BST(){
            root = NULL;
        }
        void lvlOrderPrint(){  // bfs, O(n)
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
                cout<<cur->val<<" ";    
            }
            cout<<endl;
        }
        void insert(int val){    // insert node into BST
            Node *node = new Node(val);
            if (root==NULL)        // if tree empty
                root = node;
            else 
                insert(root, node);
        } 
        // for bst
        // in all function node is root node
        Node *search(Node *node, int key){  // searches a node by its value/key, O(lgn) for balanced bst, O(n) for skewed
            if (node==NULL || node->val == key)  
                return node;
            if (node->val < key)
                return search(node->left, key);
            else if(node->val > key)
                return search(node->right, key);
        }
        Node *getMin(Node *node){  // returns ptr to min ele in a bst
            if (node==NULL)
                return NULL;
            while(node->left!=NULL)
                node = node->left;
            return node;    
        }
        // https://www.youtube.com/watch?v=gcULXE7ViZw
        Node *deleteByKey(Node *root, int key) { // deletes a node from bst & return root of that bst
            if (root==NULL)
                return NULL;
            if (key < root->val)
                root->left = deleteByKey(root->left, key);
            else if(key > root->val)
                root->right = deleteByKey(root->right, key);
            else {  // node found
                if (root->left==NULL && root->right==NULL){ // leaf node
                    delete root;
                    root = NULL;
                } 
                // node with only 1 child
                else if(root->left==NULL) {
                    Node *tmp = root;
                    root = root->right;
                    delete tmp;
                }
                else if(root->right==NULL){
                    Node *tmp = root;
                    root = root->left;
                    delete tmp;
                }
                // node with two child
                else {
                    Node *min = getMin(root->right);
                    root->val = min->val;
                    root->right = deleteByKey(root->right, min->val);
                }
                return root;
            }            
                
        }
        void printNthLevelNodes(Node *root, int lvl){ // prints nth level nodes
            if (root == NULL)   
                return;
            if (lvl==1)  {
                cout<<root->val<<" ";
                return;
            }
            printNthLevelNodes(root->left, lvl-1);
            printNthLevelNodes(root->right, lvl-1);
        }

        int getHeight(Node *node){    // no of lvls + 1 = height , can be calculated by getting the longest path between root & leaf node
            if (node==NULL)
                return 0;
            return 1 + (int) max(getHeight(node->left), getHeight(node->right));    
        }
    private:
        // insertion for binary search tree
        void insert(Node* root, Node* node){      // O(lgn) for bst, if tree is balanced, O(n) if tree is skewed, n= no of nodes in tree

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
    BST bst;
    int ar[] = {6, 7, 4, 5, 10, 8, 1, 20, 3, 9};
    for (int i=0 ; i<sizeof(ar)/sizeof(ar[0]) ; i++)
        bst.insert(ar[i]);

    cout<<"height of a bst   :";
    cout<<bst.getHeight(bst.root);
    cout<<endl;

    cout<<"Max lvl in bst :";
    cout<<bst.getHeight(bst.root)-1;
    cout<<endl;

    bst.lvlOrderPrint();
    cout<<"Delete 5\n";
    bst.root = bst.deleteByKey(bst.root, 6);
    bst.lvlOrderPrint();

    cout<<"3rd level nodes\n";
    bst.printNthLevelNodes(bst.root, 3);
    cout<<endl;

    return 0;
}