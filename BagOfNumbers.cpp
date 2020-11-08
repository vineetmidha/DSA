// https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/bag-of-numbers/description/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

#include<iostream>
#include<stack>
#include<queue>

using namespace std;

void solve(stack<int> s){
    queue<int> q;

    while (!s.empty()){
        q.push(s.top());
        s.pop();
    }

    while (!q.empty()){
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}

int main() {
    int n;
    cin >> n;

    stack<int> s;

    while (n--){
        int x;
        cin >> x;
        s.push(x);
    }

    solve(s);
}
