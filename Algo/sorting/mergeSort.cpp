#include <iostream>
using namespace std;

void display(int arr[], int n){
    for (int i=0 ; i<n ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;    
}

void merge(int arr[], int start, int mid, int end){
    int n1 = mid-start+1;   // size of left arr
    int n2 = end - mid ;   // size of right arr
    int arr1[n1];
    int arr2[n2];
    for (int i=0, k=start; i<n1 ;i++,k++)
        arr1[i] = arr[k];
    for (int i=0, k=mid+1 ; i<n2 ; i++, k++)
        arr2[i] = arr[k];    

    int i=0, j=0, k=start;
    for ( ; i<n1 && j<n2; k++){
        if (arr1[i]<=arr2[j])
            arr[k] = arr1[i++];
        else 
            arr[k] = arr2[j++];    
    }    
    
    while(i<n1)
        arr[k++] = arr1[i++];
    
    while(j<n2)
        arr[k++] = arr2[j++];        
}


void mergeSort(int arr[], int start, int end){
    if (start < end) {
        int mid = (start+end)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

int main(){
    int arr[] = {4,3,2, 0, 9, 9, 1010, 2, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Inital\n";
    display(arr, n);
    mergeSort(arr, 0, n-1);
    cout<<"After Merge Sort\n";
    display(arr, n);
    return 0;
}