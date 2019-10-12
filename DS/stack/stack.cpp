// Stack using Linked List

// Push, Pop, Peek or Top, isEmpty are basic opeartions on a stack


#include <iostream>
using namespace std;

class Node{
    public:
        int val;
        Node *next;

        Node(int val){
            this->val = val;
            this->next = NULL;
        }
};

class Stack{
    public:
        Node *top;

        Stack(){
            this->top = NULL;
        }
        void push(Node *node){
            node->next = top;
            top = node;
        }
        Node *pop(void){
            if (isEmpty())
                return NULL;

            Node *ptr = top;
            top = top->next;
            ptr->next = NULL;
            return ptr;     
        }
        bool isEmpty(){
            if (top==NULL)
                return true;
            return false;     
        }
        Node *peek(){     // top or peek
            return top;
        }
};


int main(){
    Stack stack;
    
    cout<<"Is Stack empty? "<<stack.isEmpty()<<endl;
    cout<<"Insert 2 into stack\n";
    stack.push(new Node(2));
    cout<<"Is Stack empty? "<<stack.isEmpty()<<endl;
    cout<<"Top element\n"<<stack.peek()->val<<endl;
    cout<<"Inserting 4 elements into stack [1,2,3,4]\n";
    int ar[] = {1, 2, 3, 4};
    for (int i=0 ; i<sizeof(ar)/sizeof(ar[0]) ; i++)
        stack.push(new Node(ar[i]));

    cout<<"Top element\n"<<stack.peek()->val<<endl;
    
    cout<<"Popping 5 times\n";
    for (int i=0 ; i<5 ; i++)
        cout<<stack.pop()->val<<endl;


    cout<<"Is Stack empty? "<<stack.isEmpty()<<endl;

    return 0;
}