#include <iostream>
#include <cmath>
using namespace std;

/*************************************/
// naive method
bool isPrime(long long int N){
    if (N<2)
        return false;    
    for (int i=2 ; i*i<N ; i++) 
        if (N%i == 0)
            return false;

    return true;
}
/**************************************/



/***************************************************/
// optimized method

// https://www.geeksforgeeks.org/primality-test-set-1-introduction-and-school-method/

// here we check in range (2, root n)
// All Intergers above 4 can be represented by (6k+i) where i=-1,0,1,2,3,4 & any k 
// 2 divides (6k + 0), (6k + 2), (6k + 4)
// and 3 divides (6k + 3)
// so we can check all these above cases by dividing N by 2 & 3
// remaining cases (6k+1) * (6k-1), we have to check 

long long int equation1(long long int n){   // n>0
    return 6*n-1;    
}
long long int equation2(long long int n){   // n>0
    return 6*n+1;    
}

bool isPrimeEfficient(long long int N){
    if (N<2)
        return false;    
    if (N%2==0 || N%3==0)
        return false;        

    long long int limit = sqrt(N);   

    long long int i=1;
    long long int no1 = equation1(i);
    long long int no2 = equation2(i);
    while(no1<limit && no2<limit){
        if (N % no1 == 0)
            return false;
        if (N % no2 == 0)
            return false;        
        no1 = equation1(i);
        no2 = equation2(i);            
        i++;
    }    

    return true;  
}


/****************************************************/

int main(){
    long long int N = 998199991331;
    cout<<isPrimeEfficient(N)<<endl;
    return 0;
}
