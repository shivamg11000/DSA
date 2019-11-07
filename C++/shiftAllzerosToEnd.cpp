// Given an array, we have to move all zeros to the end

#include<iostream>
using namespace std;

void printArr(int arr[], int n){
    for (int i=0 ; i<n ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

// shifts all zeros to the end
// iterate array, wherever 0 found swap it with last non-zero element
void shiftZeros(int arr[], int n){   // T=O(n), S=O(1)
    int j = n-1;
    while(arr[j]==0)   // j always points to the last non-zero element
        j--;

    // iterate over array
    for(int i=0 ; i < j ; i ++) {
        if (arr[i] == 0) {
            swap(&arr[i], &arr[j]);
            while(arr[j]==0)   // j always points to the last non-zero element
                j--;
        }
    }    
}

int main() {
    int arr[] = { 1, 0, 2, 3, 4, 0, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    printArr(arr, n);
    shiftZeros(arr, n);
    printArr(arr, n);

    return 0;
}