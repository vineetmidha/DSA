// I hate Even Subarrays

// https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/i-hate-even-subarrays/description/

#include<iostream>

#include<stack>

using namespace std;

string solve(string s)
{
    stack<char> stk; 

    for (int i=0; i<s.length(); i++){
        if (stk.empty()){
            stk.push(s[i]);
        } else if (s[i] != stk.top()){
            stk.push(s[i]);
        } else if (s[i] == stk.top()){
            stk.pop();
        }
    }

    s = "";
    while (not stk.empty()){
        s = stk.top() + s;
        stk.pop();
    }

    if (s.empty())
        return "KHALI";
    else
        return s;    
}
int main()
{
    int t;
    cin >> t;

    while (t--){
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
}
