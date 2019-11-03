// Construct a complete binary tree from given array in level order fashion
// https://www.geeksforgeeks.org/construct-complete-binary-tree-given-array/

#include <iostream>
using namespace std;

class Node{
public:    
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void inOrder(Node* root){ // in order traversal  
    if (root == NULL) 
        return;
    
    inOrder(root->left); 
    cout <<root->data <<" "; 
    inOrder(root->right); 
} 

// inserts arr elements in lvl order & return root of the tree
Node* insertLevelOrder(int arr[], int i, int n) {  //  i initially zero
    // Base case for recursion
    if(i>=n)
        return NULL;

    Node *root= new Node(arr[i]);
    root->left = insertLevelOrder(arr, 2 * i + 1, n);
    root->right = insertLevelOrder(arr, 2 * i + 2, n);
    return root;
}
  
// Driver program to test above function 
int main() 
{ 
    int arr[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 

    Node* root = insertLevelOrder(arr, 0, n); 
    inOrder(root);  // print in (in order) fashion
    cout<<endl;

    return 0;
} 