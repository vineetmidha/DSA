// https://www.geeksforgeeks.org/next-greater-element/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> NextGreaterElement(vector<int> v)
{
    vector<int> result(v.size());

    stack<int> s;
 
    s.push(0);

    for (int i=1; i<v.size(); i++){
        while (!s.empty() && v[i] > v[s.top()]){
            result[s.top()] = v[i];
            s.pop();
        }

        s.push(i);
    }

    while (!s.empty()){
        result[s.top()] = -1;
        s.pop();
    }
    
    return result;
}

int main()
{
    vector<int> v = {11, 13, 21, 3};

    vector<int> result = NextGreaterElement(v);

    cout << result.size();

    for (int i=0; i<result.size(); i++){
        cout << v[i] << " => " << result[i] << endl;
    }

    return 0;
}

/*

11 => 13
13 => 21
21 => -1
3 => -1

*/
