#include <iostream>
using namespace std;

void display(int arr[], int n){
    for (int i=0 ; i<n ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;    
}

// recursive approach
int binarySearch(int arr[], int item, int l, int h) { // returns index of found item in a sorted array
    if (l>h)
        return -1;

    int mid = (l+h)/2;
    if (item < arr[mid]){
        return binarySearch(arr, item, l, mid-1);
    } 
    else if (item > arr[mid]){
        return binarySearch(arr, item, mid+1, h);
    } 
    else
        return mid; 

}


int main(){
    int arr[] = {1,3, 4, 5, 7, 9, 12, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Array\n";
    display(arr, n);
    cout<<"element 3 is at index\n";
    int idx = binarySearch(arr, 3, 0, n-1);
    cout<<idx<<endl;
    return 0;
}