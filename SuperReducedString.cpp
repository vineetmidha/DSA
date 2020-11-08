// https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/super-reduced-strings-303701dd/description/

#include<bits/stdc++.h>

using namespace std;

void solve(string s){
    if (s.empty()){
        cout << "Empty String";
        return;
    }

    stack<char> stk;

    for (auto i : s){
        if (stk.empty()){
            stk.push(i);
        } else {
            if (stk.top() == i){
                stk.pop();
            } else {
                stk.push(i);
            }
        }
    }

    if (stk.empty()){
        cout << "Empty String";
        return;
    }
    
    s = "";
    while (!stk.empty()){
        s = stk.top() + s;
        stk.pop();
    }
    cout << s;
}

int main() {
    string s;
    cin >> s;
    solve(s);
}
