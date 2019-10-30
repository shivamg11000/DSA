// in this queue has elements in order of their priority
// implemented using heaps
// insertion, deletion takes O(lgn)
// get max element takes O(1)

#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

// implementing max priority queue using max heap, refer heap to understand its implementaion
class MaxHeap{
public:
    int ar[1000];
    int start_idx;   // 1st element
    int stop_idx;    // last element

    MaxHeap(){
        ar[0] = 99999;  // we store heap starting from index 1, so we place some dumyy value at 0
        start_idx = 1;
        stop_idx = 0;  // initially heap is empty
    }  
    // returns index of child & parent
    int left(int i){return 2*i;}
    int right(int i){return 2*i+1;}
    int parent(int i){return i/2;}

    // refer to DSA/DS/heap/heap.cpp
    // build a max heap in top down fasion
    // O(lgn)
    void max_heapify(int Arr[], int i,int n){   //i=ith node, n=no of elements in heap
        if (i>n/2)   // leaf nodes
            return;
        int left = this->left(i);
        int right = this->right(i);

        int larger = i;
        if (left<=n && Arr[i] < Arr[left])
            larger = left;
        if (right<=n && Arr[larger] < Arr[right])
            larger = right;    
        if (i!=larger) {
            swap(&Arr[i], &Arr[larger]);
            max_heapify(Arr, larger, n);
        }    
    }

    int maximum(){           
        return ar[start_idx];
    }
    int extract_maximum(){        // O(lgn) to remove root aswellas build heap again
        if (stop_idx<1)  // heap empty
            return -999999;   // garbage value
        int tmp = ar[start_idx];
        ar[start_idx] = ar[stop_idx--];
        max_heapify(ar, start_idx, stop_idx-start_idx+1);
        return tmp;
    }   
    // build a max_heap in bottom up fashion
    void insert_val(int val){  // O(lgn), n= no of elements already in heap
        ar[++stop_idx] = val;
        int i = stop_idx;

        while(true) {
            int parent = this->parent(i);
            if (parent>0 && ar[parent] < ar[i]) {
                swap(&ar[parent], &ar[i]);
                i = parent;
            }
            else 
                return;    
        }
    }
    void changePriority(int i, int val){  // changes priority of element stored at ith index 
        if (ar[i] < val) {    // value larger
            ar[i] = val;
            while(true) {    // bubble up to satisfy heap property
                int parent = this->parent(i);
                if (parent>0 && ar[parent] < ar[i]) {
                    swap(&ar[parent], &ar[i]);
                    i = parent;
                }
                else
                    return;
            }
        } else {              // value smaller
            ar[i] = val;
            max_heapify(ar, i, stop_idx-start_idx+1);  // bubble down changed element
        }
    }
    void printAr(){  // print heap stored in arr
        for (int i=start_idx ; i<=stop_idx ; i++)
            cout<<ar[i]<<" ";
        cout<<endl;    
    }
};

void printAr(int ar[], int n){  // prints normal arr
    for (int i=0; i<n ; i++)
        cout<<ar[i]<<" ";
    cout<<endl; 
}

int main(){
    MaxHeap pq;  // priority queue
    int ar[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout<<"Inserting into queue\n";
    for (int i=0 ; i<sizeof(ar)/sizeof(ar[0]) ; i++)  // inserting elements in priority queue
        pq.insert_val(ar[i]);
    printAr(ar, sizeof(ar)/sizeof(ar[0]));    
    cout<<"Priority Queue\n";
    pq.printAr();

    cout<<"Removing Max element : "<<pq.extract_maximum()<<"\n";
    pq.printAr();
    cout<<"Removing Max element : "<<pq.extract_maximum()<<"\n";
    pq.printAr();
    cout<<"Removing Max element : "<<pq.extract_maximum()<<"\n";
    pq.printAr();

    cout<<"Changing Priority of 1st element to 0\n";
    pq.changePriority(1, 0);
    pq.printAr();
    return 0;
}
