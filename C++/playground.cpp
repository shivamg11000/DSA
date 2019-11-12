#include <bits/stdc++.h>
using namespace std;

int case1(int n){   
    int i = pow(n, 0.5);
    while(i>1) {
        if (n % i == 0){
            n = n/i;
            break;
        } 
        i--;
    }
    return n;
}
int case2(int n){
    return n-1;
}

int downToZero(int n) {
    /*
     * Write your code here.
     */
    int count = 0;
    while(n!=0) {
        int tmp = case1(n);
        if (tmp == n)      // case1 not applicable
            n = case2(n); 
        else 
            n = tmp;        // case1 applicable
        cout<<n<<" ";    
        count++;        
    }
    return count;

}

void swap(long long int *a, long long int *b){
    long long int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
void print(vector<long long int> v){
    for(int i=0 ; i<v.size() ; i++)
        cout<<v[i]<<" ";
    cout<<endl;    
}

struct info{
    int operation;
    string w;
    unsigned int k;
};

class TextEditor{

public:
    string s;    // using only push_back() & pop_back()
    int len;
    stack<info> state;
    TextEditor(){s = ""; len=0;}

    void append(string txt){
        for (int i=0 ; txt[i]!='\0' ; i++){
            s.push_back(txt[i]);
            len++;
        }
        state.push({
            1,
            txt,
            0       // garbage value
        });
    }
    void _delete(unsigned int k){
        string erased = "";
        while(k>0){
            erased.push_back(s[len-1]);
            s.pop_back();
            k--;
            len--;
        }
        state.push({
            2,
            erased,      
            k
        });
    }
    void print(unsigned int k){
        if (k>len-1)
            return;
        cout<<s[k-1]<<endl;
    }
    void printAll(){
        cout<<endl<<s<<endl;
    }
    void printStack(stack<info> state){
        while(!state.empty()){
            info cur = state.top();
            state.pop();
            cout<<cur.operation<<" "<<cur.k<<" "<<cur.w<<endl;
        }
    }
};

int main(){
    /*
    cout<<endl<<downToZero(808707)<<endl;
    vector<long long int> v;
    v.push_back(1);
    v.push_back(2);
    print(v);
    swap(&v[0], &v[1]);
    print(v);
*/
    TextEditor editor;
    string s = "abc";
    editor.append(s);
    editor.append(s);
    editor._delete(2);
    editor.printStack(editor.state);
    editor.printAll();

    return 0;
}