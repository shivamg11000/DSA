// Counting occurence of digits in an array

#include<iostream>
#include<unordered_map>
using namespace std;

int main(void){
    int arr[] = {1, 1, 1, 2, 2, 3, 4, 5, 8, 9, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    unordered_map<int, int> umap;
    for (int i=0 ; i<n ; i++)
        if (umap[arr[i]])
            umap[arr[i]] += 1;
        else
            umap[arr[i]] = 1;

    unordered_map<int, int>:: iterator p; 
    cout<<"(Digit, occurred)\n";
    for (p = umap.begin(); p != umap.end(); p++) 
        cout << "(" << p->first << ", \t" << p->second << ")\n";    

    return 0;            
             
}