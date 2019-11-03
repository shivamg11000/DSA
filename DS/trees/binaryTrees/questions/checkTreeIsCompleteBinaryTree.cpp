// To check a binary tree is complete or not

// https://www.techiedelight.com/check-given-binary-tree-complete-binary-tree-not/
// https://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-complete-tree-or-not/


// approach 
// traverse tree in lvl order until a NON-FULL Node(without left or right node or no child) found. 
// Then all remaining nodes must be leaf nodes. If not then it is not complete binary tree
// Also for all nodes who have no left child but have a right child is not a complete binary tree.

#include <iostream>
#include <queue>
using namespace std;

class Node{
    public: 
        int data;
        Node *left;
        Node *right;
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

// check whether a tree is complete or not
// T = O(n), S = O(n)
bool isComplete(Node *root){     
    queue<Node *> q;

    bool nonFullNodeFound = false;
    q.push(root);
    while(!q.empty()){         // traverse tree in lvl order 
        Node *cur = q.front();
        q.pop();

        if (nonFullNodeFound && (cur->left!=NULL || cur->right!=NULL)) // remaining nodes after 1st nonFull node must be leaf node
            return false;
        if (cur->left==NULL && cur->right!=NULL)     // if a node does not have left child than it must also not have right child 
            return false;    

        if (cur->left != NULL)
            q.push(cur->left);
        if (cur->right != NULL)
            q.push(cur->right);
            
        if (cur->left==NULL || cur->right==NULL)  // 1st non full node found
            nonFullNodeFound = true;        
    }
    return true;
}


int main(){
    Node* root = NULL;
    /* Construct below tree
              1
           /    \
          2      3
         / \    / \
        4   5  6   7
    */
    
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    if (isComplete(root))
        cout << "Given binary tree is a Complete Binary Tree\n";
    else
        cout << "Given binary tree is not a Complete Binary Tree\n";
    return 0;
}