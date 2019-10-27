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

void bubbleSort(int ar[], int n){
    for(int i=1 ; i<n ; i++){
        for (int j=0 ; j<n-i ; j++){ 
            if (ar[j] > ar[j+1])
                swap(&ar[j], &ar[j+1]);
        }
    }
}

int main(){
    int arr[] = {4,3,2, 0, 9, 9, 1010, 2, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Inital\n";
    display(arr, n);
    bubbleSort(arr, n);
    cout<<"After Bubble Sort\n";
    display(arr, n);
    return 0;
}