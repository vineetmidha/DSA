# Implementation of stack using array

#include <iostream>
using namespace std;

class stack {
    int *info;
    int length;
    int top;
    
public:
    stack (int size = 5){
        top = -1;
        info = new int[size];
        length = size;
    }
    void push(int x){
        if (top == length-1){
            cout << "Stack full" << endl;
            return;
        }
        
        info[++top] = x;
    }
    int pop(){
        if (isEmpty()){
            cout << "Stack empty" << endl;
            return -1;
        }
        return info[top--];        
    }
    bool isEmpty(){
        return top == -1;
    }
    int peek(){
        return info[top];
    }
};

int main() {
    stack s(5);
    
    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << s.peek() << endl;
    
    while (not s.isEmpty()){
        cout << s.pop() << " ";
    }
	return 0;
}
