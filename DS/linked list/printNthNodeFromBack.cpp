#include <iostream>
using namespace std;

class Node{
    public:
        int value;
        Node *next;
        Node(int value){
            this->value = value;
            next = NULL;
        }
};

void printList(Node *root){
    while(root!=NULL){
        cout<<root->value<<" ";
        root = root->next;
    }
    cout<<endl;
}

Node *addNode(Node *root, int value){
    Node *node = new Node(value);
    if (root==NULL){
        root = node;
        return root;
    }

    Node *cur = root;
    while(cur->next!=NULL)
        cur = cur->next;

    cur->next = node;
    return root;
}

void printNthNodeFromBack(Node *root, int n){
    Node *ptr1=root, *ptr2=root;
    while(n>1 && ptr1->next!=NULL){  // traverse nth node from start of list, then ptr1 points at nth node from start
        ptr1 = ptr1->next;
        n--;
    }
    while(ptr1->next != NULL){  // traverse ptr2 starting from root until ptr1 points at last element
        ptr2 = ptr2->next;
        ptr1 = ptr1->next;
    }
    cout<<ptr2->value<<endl;          // nth node from back
}

int main() {
    Node *root = NULL;

    int ar[] = {2, 1, 4, 6, 8, 10, 3, 12, 7};
    for (int i=0 ; i<sizeof(ar)/sizeof(ar[i]) ; i++)
        root = addNode(root, ar[i]);

    cout<<"Linked List\n";    
    printList(root);

    cout<<"3rd node from back of list\n";
    printNthNodeFromBack(root, 3);
    return 0;
}