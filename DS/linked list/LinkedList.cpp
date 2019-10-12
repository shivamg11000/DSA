#include <iostream>
using namespace std;

class Node{
    public:
        float data;
        Node *next;
        Node(float data){
            this->data = data;
            this->next = NULL;
        }
};

class List{       // LinkedList
    public:
        Node *head;
        int size;
        List(){
            this->head = NULL;
            this->size = 0;    
        }

        bool isEmpty(){
            if (size<1)
                return true;
            return false;    
        }
        void add(float val){   // inserts node a end
            Node *node = new Node(val);
            if (head==NULL){
                head = node;
                size++;
                return;
            }

            Node *current=head;
            while(current->next!=NULL) {
                current = current->next;
            }
            current->next = node;
            size++;
        }
        int indexOf(float val){
            Node *current = head;
            int i=0;
            while(current!=NULL){
                if (current->data == val)
                    break;
                current = current->next;
                i++;
            }
            return i;

        }
        float valueAt(int index){
            if (index<0 || index>size-1)    
                return -9999999;
            int i=0;
            Node *current = head;
            while(current!=NULL){
                if (i==index)   
                    break;
                current = current->next;
                i++;
            }
            return current->data;
        }
        void addAt(int index, float val){
            if (index > size || index < 0)  // out of bound
                return;

            Node *newNode = new Node(val);

            Node *current = head;
            Node *prev = NULL;
            int i=0;
            while(current->next!=NULL && i<index){
                prev = current;
                current = current->next;
                i++;
            }
            if (i==0) {               // add at beginning
                newNode->next = head;
                head = newNode;
            }
            else if (current->next==NULL) {     // add at end
                current->next = newNode;
            } 
            else if (i==index) {      // add in between
                prev->next = newNode;
                newNode->next = current;
            } 
            size++;
        }
        void deleteAt(int index){
            if (index > size-1 || index < 0)  // out of bound
                return;
            if (this->isEmpty())
                return;    

            Node *current = head;
            Node *prev = NULL;
            int i=0;
            while (current->next!=NULL && i<index) {
                prev = current;
                current = current->next;
                i++;
            }
            if (i==0) {   // delete at start
                head = current->next;
            }
            else if(i==size-1) {   // delete at end
                prev->next = NULL;
            }   
            else {          // in between
                prev->next = current->next;
            }
            delete current;
            size--;

        }
        void reverse(){
            if (this->size < 2)
                return;
                
            Node *prev = NULL;
            Node *current = head;
            Node *after = current->next;

            while(current->next!=NULL) {
                current->next = prev;
                prev = current;
                current = after;
                after = after->next;
            }   
            current->next = prev;
            head = current;

        }
        void display(){
            Node *current = head;
            while(current!=NULL){
                cout<<current->data<<" ";
                current = current->next;
            }
            cout<<endl;
        }
};

int main(){
    List list;
    float ar[] = {2, 1, 0, 2.23, 9, 1, 2, 6};
    for (int i=0 ; i<sizeof(ar)/sizeof(ar[0]) ; i++)
        list.add(ar[i]);

    cout<<"LinkedList\n";
    list.display();
    cout<<"value at 0 "<<list.valueAt(0)<<endl;

    cout<<"value at 4 "<<list.valueAt(4)<<endl;
    cout<<"index of 2 "<<list.indexOf(2)<<endl;
    cout<<"index of 9 "<<list.indexOf(9)<<endl;

    cout<<"After adding 8 at 2nd index\n";
    list.addAt(2, 8);
    list.display();
    cout<<"size "<<list.size<<endl;

    cout<<"After deleting at last index\n";
    list.deleteAt(list.size-1);
    list.display();
    cout<<"size "<<list.size<<endl;

    cout<<"LinkedList after reversing\n";
    list.reverse();
    list.display();
    return 0;
} 