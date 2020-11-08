// https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/minimum-add-to-make-parentheses-valid-9cba6259/description/

#include<bits/stdc++.h>

using namespace std;

int solve(string s){
    stack<char> stk;

    int c = 0;

    for (auto i : s){
        if (i == '('){
            stk.push(i);
        } else if (i == ')'){
            if (stk.empty()){
                c++;
            } else {
                stk.pop();
            }
        }
    }

    return c + stk.size();
}

int main(){
    string s;
    cin >> s;
    cout << solve(s);
}

/*

Input: ()))((
Output: 4

*/
