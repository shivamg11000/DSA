
#include <iostream>
using namespace std;

void display(int arr[], int n){
    for (int i=0 ; i<n ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;    
}

void insertionSort(int arr[], int n){
    int j, tmp;
    for (int i=1 ; i<n ; i++){
        j = i-1;
        tmp = arr[i];
        while (j>-1 && tmp<arr[j]) {
            arr[j+1] = arr[j];    
            j--;
        }
        arr[j+1] = tmp;
        display(arr, n);
    }
}

int main(){
    int arr[] = {4,3,2, 1, 9, 9, 1010, 2, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Inital\n";
    display(arr, n);
    insertionSort(arr, n);
    cout<<"After Insertion Sort\n";
    display(arr, n);
    return 0;
}