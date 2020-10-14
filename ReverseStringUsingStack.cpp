// Reverse a string using stack - iterative and recursive

#include <iostream>
#include <stack>

using namespace std;

string reverse_iterative (string s) {
    if (s.length()==1){
        return s;
    }
    
    stack <char> stk;
    
    for (auto i: s){
        stk.push(i);
    }
    
    s.clear();
    
    while (!stk.empty()){
        s.push_back(stk.top());
        stk.pop();
    }
    
    return s;
}

string reverse_recursive(string s){
    if (s.length()==0){
        return string();
    }
    
    string ans = reverse_recursive(s.substr(1));
    return ans + s.at(0);
}

int main() {
    int t;
    cin >> t;
    
    while (t-- > 0) {
        string s;
        
        cin >> s;
        
        cout << reverse_iterative(s) << endl;
        cout << reverse_recursive(s) << endl;    }
	return 0;
}

/*

Input:

5
this
program
reverses
a
string

Output:

siht
margorp
sesrever
a
gnirts
*/
