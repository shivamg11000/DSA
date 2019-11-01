// https://www.youtube.com/watch?v=B6Tsrmgsy3k

// Given N=3 Arrays, find common elements in them

#include <iostream>
#include <vector>
using namespace std;

// T = O(n1 + n2 + n3) , S = O(1), no auxillary space is used from implementing this, vector is only used to output solution 
// works for sorted arrats only
vector<int> findIntersection(int ar1[], int ar2[], int ar3[], int n1, int n2, int n3) {  // all arrays are sorted
    vector<int> common;
    int i=0, j=0, k=0;
    while(i<n1 && j<n2 && k<n3){
        if (ar1[i] == ar2[j] && ar2[j]== ar3[k]) {
            common.push_back(ar1[i]);
            i++;
            j++;
            k++;
        }
        else if(ar1[i]<ar2[j])    // no possibility of finding ar1[i] in other two arrays
            i++;
        else if(ar2[j]<ar3[k])    // same for ar2[j]
            j++;
        else                      // same from ar3[k]
            k++;        
    }
    return common;
};

int main(){
    int ar1[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 90};
    int ar2[7] = {1, 9, 10, 20, 30, 50, 90};
    int ar3[7] = {-10, -5, 0, 1, 23, 90, 100};

    vector<int> intersection = findIntersection(ar1, ar2, ar3, 11, 7, 7);

    for (int i=0 ; i<intersection.size() ; i++)
        cout<<intersection[i]<<" ";
    cout<<endl;

    return 0;
}