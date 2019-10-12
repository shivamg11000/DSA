// O(n*n

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

Node *insert(Node *root, int item){
    Node *newNode = new Node(item);

    if (root==NULL)
        root = newNode;
    else{
        Node *current = root;
        while(current->link!=NULL){
            current = current->link;
        }
        current->link = newNode;
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

Node *arrayToList(int arr[], int n) 
{ 
    Node *root = NULL; 
    for (int i = 0; i < n; i++) 
        root = insert(root, arr[i]); 
   return root; 
} 

int main(){
    int arr[] = { 1, 2, 6, 4, 5 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    Node* root = arrayToList(arr, n); 
    display(root); 
    return 0;
}
