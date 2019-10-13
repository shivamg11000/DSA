// predefined stack used 

#include <iostream>
#include <stack>
using namespace std;


bool isParaBalanced(string str) {
    stack<char> s;
    char c;
    
    for (int i=0 ; i<str.length() ; i++) {
        c = str[i];
        if (c=='(' || c=='[' || c=='{') {
            s.push(c);
        }
        else if (c==')' || c==']' || c=='}') {
            if (s.empty())
                return false;
 
            switch(c){
                case ')': 
                    if (s.top()!='(')
                        return false;
                    break;
                case ']': 
                    if (s.top()!='[')
                        return false;
                    break;
                case '}': 
                    if (s.top()!='{')
                        return false;
                    break;    
            }   
            s.pop();                   // deletes the top of the element, does not return it here
        }
        else {
            cout<<"Worng character in string\n";
            return 0;
        }
    }

    if (!s.empty())
        return false;
    return true;     
}

int main(){
    
    string str = "(())[]";
    cout<<str;
    cout<<endl;
    if (isParaBalanced(str))
        cout<<"Parenthesis are balanced\n";
    else 
        cout<<"Parenthesis are not balanced\n";    

    str = "))(({}{";
    cout<<str;
    cout<<endl;
    if (isParaBalanced(str))
        cout<<"Parenthesis are balanced\n";
    else 
        cout<<"Parenthesis are not balanced\n";    

    return 0;
}