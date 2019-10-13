// front  :   pointer to first item in queue
// rear   :   pointer to last item in queue 
//  enQueue() : This operation adds a new node after rear and moves rear to the next node.
//  deQueue() : This operation removes the front node and moves front to the next node.

#include <iostream>
using namespace std;

class Node{
    public:
        float value;
        Node *next;
        Node(float value){
            this->value = value;
        }
};

class Queue{
    public:
        Node *front;
        Node *rear;
        Queue(){
            front = NULL;
            rear = NULL;
        }
        bool isEmpty(){
            return (front==NULL && rear==NULL);
        }
        void enQueue(float value){
            Node *node = new Node(value);
            if (front==NULL && rear==NULL){   // when queue empty
                front = node;
                rear = node;
            }    
            else {                           // some element in queue
                rear->next = node;
                rear = node;
            }
        }
        float deQueue(void){
            if (isEmpty())             // queue empty
                return -124234234234;
            if (front==rear){          // one element in queue    
                delete front;
                front = rear = NULL;
            }
            Node *ptr = front;
            front = front->next;

            float value = ptr->value;
            delete ptr; 
            return value;
        }

};

void showQueue(Queue* q){
    Node* ptr = q->front;
    while(ptr!=NULL){
        cout<<ptr->value<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

int main(){
    Queue q;

    cout<<"adding 2 to queue\n";
    q.enQueue(2);   
    showQueue(&q);

    cout<<"adding 5.5 to queue\n";
    q.enQueue(5.5);
    showQueue(&q);

    cout<<"adding 10 to queue\n";
    q.enQueue(10);
    showQueue(&q);
    
    cout<<"deQueing queue\n";
    q.deQueue();
    showQueue(&q);

    return 0;
}