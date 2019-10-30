// https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/tutorial/


// Binary Heap is a complete binary tree
// complete tree has all levels filled except the last/leaf level & all the leaves in the last level are to the left side
// complete binary trees can be represented in array
// There are two types of heap - min & max heap
// In max heap each node is greater than its child 
// Heap is implemented using arrays

#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void printHeapArr(int Arr[], int n){
    int start = 1;
    int stop = start + n - 1;
    for (int i=start ; i<=stop ; i++)
        cout<<Arr[i]<<" ";
    cout<<endl;    
}

// for ith node perform swaping TOP to Bottom to maintain the heap property
// O(lgN)
// performed on root of a subtree/tree
void max_heapify(int Arr[], int i, int N){  // index i starts from 1 instead of 0
    // index
    int left  = 2*i;
    int right = 2*i+1;
    int larger = i;   // assumed
    
    if(left <= N and Arr[left] > Arr[ i ] )
         larger = left;
    if(right <= N and Arr[right] > Arr[larger] )
        larger = right;
    if(larger != i) {
        swap(&Arr[i], &Arr[larger]);
        max_heapify(Arr, larger, N);
    } 
}

void build_maxheap (int Arr[], int n) //  O(n), n is no of nodes
{
    for( int i = n/2 ; i > 0 ; i--) // apply max_heapify on all non-leaf nodes, N/2...1
        max_heapify (Arr, i, n);
}

// for ith node perform swaping TOP to Bottom to maintain the heap property
// O(lgN)
void min_heapify(int Arr[], int i, int N){  // index i starts from 1 instead of 0
    // index
    int left  = 2*i;
    int right = 2*i+1;
    int smaller = i;   // assumed
    
    if(left <= N and Arr[left] < Arr[ i ] )
        smaller = left;
    if(right <= N and Arr[right] < Arr[smaller] )
        smaller = right;
    if(smaller != i) {
        swap(&Arr[i], &Arr[smaller]);
        min_heapify(Arr, smaller, N);
    } 
}

// O(N)
void build_minheap (int Arr[], int n) 
{
    for( int i = n/2 ; i > 0 ; i--) // apply max_heapify on all non-leaf nodes, N/2...1
        min_heapify (Arr, i, n);
}

void heapSort(int Arr[], int n){  // sorts in ascedngin order, O(nlgn), not a stable sort
    build_maxheap(Arr, n);
    while(n>1) {
        swap(&Arr[1], &Arr[n]);   // swap root(largest) & last element
        n--;                      // decrease size of heap
        max_heapify(Arr, 1 , n);
    }
}

void printArr(int Arr[], int n){
    for (int i=0 ; i<n ; i++)
        cout<<Arr[i]<<" ";
    cout<<endl;    
}

int main(){
    int heapArr[100], tmp[] = {10, 8, 9, 7, 6, 5, 4};
    int noOfNodes = sizeof(tmp)/sizeof(tmp[0]);

    for (int i=0, j=1 ; i<noOfNodes ; i++, j++) // heap is stored from index 1
        heapArr[j] = tmp[i];

    cout<<"Before heapify\n";
    printHeapArr(heapArr, noOfNodes);

    build_minheap(heapArr, noOfNodes);

    cout<<"After heapify\n";
    printHeapArr(heapArr, noOfNodes);

    int ar[] = {-9999999, 1, 6, 3, 2, 9 ,7, 1, 1};  // here heapSort implementation is applicable for arrays starting from index 1 so we take ar[0] some dummy value
    cout<<"Before Sorting\n";
    printArr(ar, sizeof(ar)/sizeof(ar[0]));
    heapSort(ar, sizeof(ar)/sizeof(ar[0])-1);
    cout<<"After Sorting\n";
    printArr(ar, sizeof(ar)/sizeof(ar[0]));

    return 0;        
}