// Transform the Expression - Infix to Postfix

// https://www.spoj.com/problems/ONP/

#include <bits/stdc++.h>

using namespace std;

bool isOperator(char symbol){
    switch (symbol){
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '(':
        case ')': return true;
    }
    return false;
}

int priority(char opr){
    int p = 0;
    switch (opr){
        case '+': p = 1; break;
        case '-': p = 1; break;
        case '*': p = 2; break;
        case '/': p = 2; break;
        case '^': p = 3; break;
        case '(': p = 4; break;
        case ')': p = 4; break;
    }
}

string infix2postfix(string expn){
    string postfix = "";
    stack <char> s; 
    
    for (auto elm : expn){
        if (elm == '('){
            s.push(elm);
        } else if (elm == ')') {
            while (!s.empty()) {
                int top = s.top();
                s.pop();
                if (top == '('){
                    break;
                }
                postfix += top;
            }
        } else if (isOperator(elm)){
            if (s.top() == '('){
                s.push(elm);
            } else { // if (isOperator(s.top())){
                if (priority(elm) > priority(s.top())){
                    s.push(elm);
                } else {
                    int top = s.top();
                    while (!s.empty() and priority(elm) <= priority(top) and top != '(') {
                        s.pop();
                        postfix += top;
                        top = s.top();
                    }
                    s.push(elm);
                }
            }
        } else { // operand
            postfix += elm;
        }
       //cout << postfix << endl;
    }
    return postfix;
}
int main() {
    int t;
    cin >> t;
    
    while (t--){
        string expn;
        cin >> expn;
        cout << infix2postfix(expn) << endl;
    }
	return 0;
}

/*

Input:
3
(a+(b*c))
((a+b)*(z+x))
((a+t)*((b+(a+c))^(c+d)))

Output:
abc*+
ab+zx+*
at+bac++cd+^*

*/
