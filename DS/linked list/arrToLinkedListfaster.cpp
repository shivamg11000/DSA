// 0(n)

#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *link;
    Node(int val){
        data = val;
        link = NULL;
    }    
};

// while traversing array it adds node simultaneously at the end using prev & current
// other approach is to traverse array in reverse and add item at beg of linked list 
Node *arrayToList(int arr[], int n){
    Node *root=NULL;
    Node *prev=NULL;
    Node *current=NULL;
    for (int i=0 ; i<n; i++){
        current = new Node(arr[i]);
        if (root==NULL)
            root = current;    
        if (prev!=NULL)
            prev->link = current;
        prev = current;     
    }
    return root;
}

void display(Node* root) 
{ 
    while (root != NULL) { 
        cout << root->data << " "; 
        root = root->link; 
    } 
}

int main(){
    int arr[] = { 1, 0, 6, 4, 5, 1, 1, 231, 12 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    Node* root = arrayToList(arr, n); 
    display(root); 
    return 0;
}
