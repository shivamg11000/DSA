#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    int ar[] = {1, 2, 3, 4, 5};
    for (int i=0 ; i<sizeof(ar)/sizeof(ar[i]) ; i++)
        v.push_back(ar[i]);
        
    for (int i=0 ; i<v.size() ; i++)
        cout<<v[i]<<" ";
    cout<<endl;    
    return 0;
}