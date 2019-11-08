// https://www.youtube.com/results?search_query=hashing+abdul+bari


// using array to implement hash table / hash map
// in c++ stl hastTable is named unordered_map

#include <iostream>
using namespace std;
#define SIZE 10

class Node{
    public:
        int data;
};

class HashTable{   // using closed hashing( linear probing )
public:
    Node *arr[SIZE];
    int n;      // no of items in hashtable           

    HashTable(){
        for(int i=0 ; i<SIZE ; i++)   // initialize arr to point NULL at all indexes
            arr[i] = NULL;
        n = 0;    
    }

    int hashFnc(int data){   // hashing fnc
        return data % SIZE;
    }
    Node *newNode(int data){
        Node *node = new Node();
        node->data = data;
        return node;
    }
    // T = O(1)
    void insert(int data){   // insert operation
        if (n >= SIZE ) {
            cout<<"HashTable is full\n";
            return;
        }

        Node *node = newNode(data);
        int idx = hashFnc(data);
        if (arr[idx] == NULL)
            arr[idx] = node;
        else {         // chaining(linear probing)
            int i=0;
            while(arr[(idx+i) % SIZE] != NULL)  // find empty place
                i++;
            arr[(idx+i) % SIZE] = node;     
        }
        n++;
    }   
    // T = O(1)
    Node *search(int data){
        int idx = hashFnc(data);
        if (arr[idx]==NULL) {
            cout<<data<<" does not exist\n";
            return NULL;  
        }
        while(arr[idx]->data != data) {   // scaning to find the data
            idx++;
            idx = idx % SIZE;
        }
        return arr[idx];    
    }
    void printHT(){
        for (int i=0 ; i<SIZE ; i++)
            if (arr[i] == NULL)
                cout<<"empty ";
            else    
                cout<<arr[i]->data<<" ";
        cout<<endl;
    }
};

int main(void){
    int ar[] = {1, 5, 9, 20, 26, 2, 4, 999, 0, 22};
    int n = sizeof(ar)/sizeof(ar[0]);

    HashTable ht;
    // insert into hashTable
    for (int i=0 ; i<n ; i++)
        ht.insert(ar[i]);
    // print hastTable after insertion
    ht.printHT();
    // search 999
    cout<<"Search 999\n";
    cout<<ht.search(999)->data<<endl;

    return 0;
}