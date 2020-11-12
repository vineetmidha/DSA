#include<iostream>
#include<stack>

using namespace std;

bool solve(string s)
{
    stack<int> stk;
    
    for (int i=0; i<s.length(); i++){
        if (s[i]!=')'){
            stk.push(s[i]);
        } else {
            if (stk.top()=='(') return true;
            
            while (!stk.empty() && stk.top() != '('){
                stk.pop();
            }
            
            if (!stk.empty()) stk.pop();
        }
    }
    return false;
}
int main()
{
    string s;
    cin >> s;
    
    cout << solve (s);
}

/*
((a+b)+((c+d))) - true
(((a+(b)))+(c+d)) - true
(((a+(b))+c+d)) - true
((a+b)+(c+d)) - false
((a+(b))+(c+d)) - false

*/
