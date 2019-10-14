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
        Node *_top;

        Stack(){
            this->_top = NULL;
        }
        void push(int val){
            Node *node = new Node(val);
            node->next = _top;
            _top = node;
            cout<<node->val<<" pushed to stack\n";
        }
        void pop(void){     // deletes top of the stack, but does not return it
            if (isEmpty())
                return;

            Node *ptr = _top;
            _top = _top->next;
            delete ptr;    
        }
        bool isEmpty(){
            if (_top==NULL)
                return true;
            return false;     
        }
        int top(){     // returns top of the stack, stack remains unchanged
            return _top->val;
        }
};


int main(){
    Stack stack;
    
    cout<<"Is Stack empty? "<<stack.isEmpty()<<endl;
    cout<<"Insert 2 into stack\n";
    stack.push(2);
    cout<<"Is Stack empty? "<<stack.isEmpty()<<endl;
    cout<<"Top element\n"<<stack.top()<<endl;
    cout<<"Inserting 4 elements into stack [1,2,3,4]\n";
    int ar[] = {1, 2, 3, 4};
    for (int i=0 ; i<sizeof(ar)/sizeof(ar[0]) ; i++)
        stack.push(ar[i]);

    cout<<"Top element\n"<<stack.top()<<endl;
    
    cout<<"Popping 5 times\n";
    for (int i=0 ; i<5 ; i++)
        stack.pop();


    cout<<"Is Stack empty? "<<stack.isEmpty()<<endl;

    return 0;
}