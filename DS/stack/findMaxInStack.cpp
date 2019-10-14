// To find Max in a Stack
// 1) Naive Way - Sequentially search for max, time=O(n)  
// 2) Efficient Way - Using Auxillary Stack,   time=O(1), space=doubles as two stacks are used

// https://www.geeksforgeeks.org/tracking-current-maximum-element-in-a-stack/

#include <iostream>
#include <stack>
using namespace std;

int getMaxFromStack(stack<int> *auxs){   // return top value of aux stack
    return auxs->top();
}
void pushOp(        // push opeartion with auxillary stack
    stack<int> *s,
    stack<int> *auxs, 
    int x
    ){ 
        cout<<x<<" pushed to stack\n";
        if (s->empty()){   // for first element to be pushed in stack
            s->push(x);
            auxs->push(x);
            return;
        }
        s->push(x);
        if (auxs->top() <= x){   // if nxt elemnt is grtr/equal to top of auxs, push it
            auxs->push(x);
        } else {
            auxs->push(auxs->top()); //if nxt el is lesser, push top of auxs again on it
        }
}
void popOp(        // pop opeartion with auxillary stack
    stack<int> *s,
    stack<int> *auxs
    ){ 
        if (s->empty()){   // stack empty
            return;
        }
        cout<<s->top()<<" popped from stack\n";
        s->pop();
        auxs->pop();
}

int main() {
    stack<int> s, auxs;         // stack & auxillary stack
    int ar[] = {40, 5, 1, 3, 9,100};    

    for (int i=0 ; i<sizeof(ar)/sizeof(ar[0]) ; i++)
        pushOp(&s, &auxs, ar[i]);

    cout<<"Max From stack\n";
    cout<<getMaxFromStack(&auxs)<<endl;    
    
    popOp(&s, &auxs);
    cout<<"Max From stack\n";
    cout<<getMaxFromStack(&auxs)<<endl;

    popOp(&s, &auxs);
    cout<<"Max From stack\n";
    cout<<getMaxFromStack(&auxs)<<endl;
    
    popOp(&s, &auxs);
    cout<<"Max From stack\n";
    cout<<getMaxFromStack(&auxs)<<endl;

    return 0;
}
