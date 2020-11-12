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
            
            while (stk.top() != '('){
                stk.pop();
            }
            
            stk.pop();
        }
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    
    while (n--){
        string s;
        cin >> s;
        
        cout << solve (s) << endl;
    }
}

/*
5
((a+b)+((c+d))) - true
(((a+(b)))+(c+d)) - true
(((a+(b))+c+d)) - true
((a+b)+(c+d)) - false
((a+(b))+(c+d)) - false

*/
