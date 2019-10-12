// Here We try to find the correct position of a pivot element(chosen) in the array
// such that the all elements are smaller to the left & all elements are greater to the right of pivot
// This step is called partition. After this step we find the correct position of the pivot element 
// meant to be in the sorted array. 
// Then we apply the same procedure recursively in the left & right sub array excluding the pivot element as it is alreay in the right position

#include <iostream>
using namespace std;

void display(int arr[], int n){
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

// partions a array such that all elements to the left are smaller than pivot 
// & all elements to the right are larger 
// here last element is taken as pivot
// here we try to put all smaller elements than pivot in a subarray at the beginning of the original array
// then puts pivot at the last of this subarray, such that we get the our partitioned array having smaller to the left & larger to the right
int partition(int arr[], int start, int end){
    int pivot = end;
    int j = start;

    for (int i=start ; i<=end-1 ; i++) {
        if (arr[pivot] > arr[i]){
            swap(&arr[i], &arr[j]);
            j++;
        }
    }
    swap(&arr[pivot], &arr[j]);
    pivot = j;
    return pivot;
}


void quickSort(int arr[], int start, int end)  
{  
    if (start < end)  
    {  
        int pivot = partition(arr, start, end);  
        quickSort(arr, start, pivot - 1);  
        quickSort(arr, pivot + 1, end);  
    }  
} 

int main(){
    int arr[] = {4,3,2, 0, 9, 9, 1010, 2, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Inital\n";
    display(arr, n);
    quickSort(arr, 0, n-1);
    cout<<"After Merge Sort\n";
    display(arr, n);
    return 0;
}