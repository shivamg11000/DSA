// nearly sorted array is given, each element is at most k elements far away from its correct posiiton such that the array is sorted.
// https://www.geeksforgeeks.org/nearly-sorted-algorithm/
// https://www.youtube.com/watch?v=yQ84lk-EXTQ


#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void printArr(int Arr[], int n){
    for (int i=0 ; i<n ; i++)
        cout<<Arr[i]<<" ";
    cout<<endl;    
}

// priority queue is implemented using heap, so here heap & priority queue structure are same
class minPriorityQueue{
    int *ar;
    int size;       // max size
    int n;          // index of last element 
public:
    minPriorityQueue(int size){
        ar = new int[size];
        this->size = size;
        n = -1;   // for zero elements
    }
    ~minPriorityQueue(){
        delete [] ar;
    }
    int left(int i){return 2*i+1;}
    int right(int i){return 2*i+2;}
    int parent(int i){return (i-1)/2;}
    bool empty(){return (n < 0 ? true : false);}
    
    void enqueue(int val){  // O(lgn)
        if (n==size-1) {
            cout<<"queue full\n";
            return;
        }
        n++;
        ar[n] = val;
        int i=n;
        while(true) { // heapify bottom to UP
            int parent = this->parent(i);
            if (parent>-1 && ar[parent] > ar[i]){
                swap(&ar[i], &ar[parent]);
                i = parent;
            }
            else
                return;    
        }
            
    }
    int dequeue(){    // O(lgn)
        int tmp = ar[0];
        ar[0] = ar[n--];
        int i=0, left, right, smaller;
        while(true) {  // heapify top to bottom
            left = this->left(i);
            right = this->right(i);
            smaller = i;
            if (left<=n && ar[left] < ar[i])
                smaller = left;
            if (right<=n && ar[right] < ar[smaller])
                smaller = right;

            if (i!=smaller) {
                swap(&ar[smaller], &ar[i]);
                i = smaller;
            } 
            else 
                break;     
        }
        return tmp;
    }
    void print(){
        for (int i=0 ; i<=n ; i++)
            cout<<ar[i]<<" ";
        cout<<endl;               
    }
};

// sorts nearly sorted array, O(nlgk)
void sortK(int arr[], int k, int n){
    minPriorityQueue pq(k+1);
    for (int i=0 ; i<k+1 ; i++)
        pq.enqueue(arr[i]);

    int j=0;
    for (int i=k+1 ; i<n ; i++, j++) {
        arr[j] = pq.dequeue();
        pq.enqueue(arr[i]);
    }
    while(!pq.empty())
        arr[j++] = pq.dequeue();
}

int main() {
    int k = 3; 
    int arr[] = { 2, 6, 3, 12, 56, 8 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 

    printArr(arr, n);
    sortK(arr, k, n);
    printArr(arr, n);

    return 0;
}