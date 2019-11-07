// A tree whose elements have at most 2 children is called a binary tree
// A binary tree whoes left subtree containes lesser values & right subtree contain greater values is called a binary search tree

// command to compile this file -> g++ -std=c++11 fileName.cpp 

// https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/

#include <iostream>
using namespace std;

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

// some info about a binary tree/subtree 
struct info{
    bool isBST;
    int max;    // max value in a tree/subtree
    int min;     // min
};

// works in bottom up fasion & visits every node, O(n)
info isTreeBST(Node *root) {  
    if (root==NULL) 
        return {false, 1, 1};  // min/max garbage val

    // recurive approach
    info leftSubTreeInfo = isTreeBST(root->left);
    info rightSubTreeInfo = isTreeBST(root->right);
    if (leftSubTreeInfo.isBST && rightSubTreeInfo.isBST){   // if left & right subtree both are BST
        // then max val in left subtree should be lesser than current node & min val in right should be greater than current node
        if ((root->val > leftSubTreeInfo.max) && (root->val < rightSubTreeInfo.min)){  
            return {true, rightSubTreeInfo.max, leftSubTreeInfo.min};  // return info about current tree/subtree
        }   
    }
    // base cases are after recursive fn as we have to solve the problem in bottom up fashion, after recursive call is done the algo backtracks up in the tree
    if (root->left==NULL && root->right==NULL)
        return {true, root->val, root->val};
    else if (root->left==NULL && (root->val < root->right->val))
        return {true, root->right->val, root->val};
    else if (root->right==NULL && (root->val > root->left->val))
        return {true, root->val, root->left->val};

    return {false, 1, 1};    // min, max are some garbage value here
}

int main(void){
    Node* root = NULL;
    /* Construct below tree
              10
           /    \
          3      15
         / \    / \
        2   5 12   20
                     \
                      22
    */
    root = new Node(10);
    root->left = new Node(3);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(5);
    root->right->left = new Node(12);
    root->right->right = new Node(20);
    root->right->right->right = new Node(22);

    cout<<"Is tree is BST\n";
    cout<<isTreeBST(root).isBST<<endl;

    return 0;
}