
// Reverse stack without using additional stack

#include <iostream>
#include <stack>

using namespace std;

void reverse_stack(stack<int> s){
    if (s.empty()){
        return;
    }
    
    int popped = s.top();
    s.pop();
    reverse_stack(s);
    s.push(popped);
}

int main() {
    
    int n, x;
    
    cin>>n;
    
    stack<int> s;
    
    for (int i = 0; i < n; i++){
        cin>>x;
        s.push(x);
    }
    
    reverse_stack(s);
    
    while (!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    
	return 0;
}

/*
Input:
5
1
2
3
4
5
Output:
5
4
3
2
1
*/
