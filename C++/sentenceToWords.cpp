#include <bits/stdc++.h> 
using namespace std; 
   
vector<string> sentenceToWords(string str){   // break sentences to words 
    vector<string> words;
    
    // breaking input into word using string stream 
    stringstream ss(str);  // Used for breaking words 
    string word;           // To store individual words 
    while (ss >> word) 
        words.push_back(word);        
    return words;
} 
  
// for debugging
void print(vector<string> v){
    for (int i=0 ; i<v.size() ; i++)
        cout<<v[i];
    cout<<endl;    
}  

int main() 
{ 
    string str = "I am Mr John Doe";
    vector<string> words = sentenceToWords(str); 
    print(words);
    return 0; 
} 