// implementing a queue using two stacks
// https://www.youtube.com/watch?v=71kEvXsEKYQ
// https://www.geeksforgeeks.org/implement-stack-using-queue/

#include<iostream>
#include<stack>
using namespace std;


class queue{    // implementing using two stacks
public:
    stack<int> s1;  // enqueue done on s1
    stack<int> s2;  // dequeue done on s2 

    void enqueue(int data){ // T=O(1)
        s1.push(data);
    }
    int dequeue(){          // T=O(n)
        if (s2.empty() && s1.empty()) // underflow
            cout<<"queue empty\n";

        int tmp;
        if (s2.empty()) {   // if s2 empty
            while(!s1.empty()){   // pop all elements from s1 & simultaneously push into s2
                s2.push(s1.top());
                s1.pop();
            }
        }
        // pop s2
        tmp = s2.top();    
        s2.pop();
        return tmp;
    }
    // helper fnc
    void print(stack<int> s1, stack<int> s2){ // print queue from front, printing a queue which is implemented using two stacks
        while (!s2.empty()){
            cout<<s2.top()<<" ";
            s2.pop();
        }
        stack<int> s3;
        while(!s1.empty()){
            s3.push(s1.top());
            s1.pop();
        }
        while(!s3.empty()){
            cout<<s3.top()<<" ";
            s3.pop();
        }
        cout<<endl;
    }
};

class _queue{  // queue using 1 stack (using 1 user stack & one call stack)
public:
    stack<int> s;

    void enqueue(int data){
        s.push(data);
    }
    int dequeue(){
        int cur = s.top();
        s.pop();
        int res;
        if (!s.empty())
            res = dequeue();
        else 
            return cur;    
        
        s.push(cur);
        return res;
    }
    // helper fn
    void print(){  // prints queue which is implemented using 1 user stack
        int cur = s.top();
        s.pop();
        if (!s.empty())
            print();

        cout<<cur<<" ";
        s.push(cur);    
    }
};

int main(void){
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    q.enqueue(9);
    q.enqueue(0);
    q.dequeue();
    q.enqueue(100);
    q.dequeue();

    q.print(q.s1, q.s2);

    return 0;
}