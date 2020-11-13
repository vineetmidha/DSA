// https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/nearest-smaller-element-929558b4/description/

#include<bits/stdc++.h>

using namespace std;

void nextSmallerElement(vector<int> v)
{
    vector<int> result(v.size());

    stack<int> s;
 
    s.push(v.size()-1);

    for (int i=v.size()-2; i>=0; i--){
        while (!s.empty() && v[i] < v[s.top()]){
            result[s.top()] = v[i];
            s.pop();
        }

        s.push(i);
    }

    while (!s.empty()){
        result[s.top()] = -1;
        s.pop();
    }
    
    for (auto i: result){
        cout << i << " ";
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> v;

    while (n--){
        int x;
        cin >> x;

        v.push_back(x);
    }

    nextSmallerElement(v);
}

// Solution by Hacker Earth

    vector<int> prevSmaller(vector<int> &A) {
        stack<int> s;
        int n = A.size();
        vector <int> res;
        for (int i = 0; i < n; i ++) {
            if (s.empty()) {
                res.push_back(-1);
                s.push(A[i]);
                continue;
            }
            while (!s.empty() && s.top() >= A[i]) {
                s.pop();
            }
            if (s.empty()) {
                res.push_back(-1);
            } else {
                res.push_back(s.top());
            }
            s.push(A[i]);
        }
        return res;
    }


/*
Input:
8
39 27 11 4 24 32 32 1
9
2 5 9 3  1 12 6 8 7

Output:
-1 -1 -1 -1 4 24 24 -1
-1 2 5 2 -1 1 1 6 6
*/
