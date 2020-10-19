// Implementation of stack

#include <iostream>
using namespace std;

class node {
    int info;
    node *next;
public:
    node (int x = 0, node * link = nullptr) {
        info = x;
        next = link;
    }
    
    void setNext(node * link){
        next = link;
    }
    
    int getInfo(){
        return info;
    }
    
    node * getNext(){
        return next;
    }
};

class stack {
    node * top;
public:
    stack(){
        top = nullptr;
    }
    
    void push(int x){
        node * fresh = new node (x);
        
        if (fresh == nullptr){
            cout << "Memory allocation failed" << endl;
            return;
        }
        
        fresh->setNext(top);
        top = fresh;
    }
    
    int pop(){
        if (top == nullptr){
            cout << "Stack empty" << endl;
            return -1;
        }
        
        node * current = top;
        
        int info = current->getInfo();
        
        top = top->getNext();
        
        delete current;
        
        return info;
    }
    
    void display(){
        if (top == nullptr){
            cout << "Stack empty" << endl;
            return;
        }
        
        node * current = top;
        
        while (current != nullptr){
            cout << current->getInfo() << " <= ";
            current = current->getNext();
        }
        
        cout << endl;
    }
};
int main() {
    int n;
    cin >> n;
    
    int a[n];
    
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    
    stack s;
    
    for (int i=0; i<n; i++){
        s.push(a[i]);
    }
    
    cout << "Stack Contents: ";
    
    s.display();
    
    cout << "Popping stack: ";
    
    for (int i=0; i<n; i++){
        cout << s.pop() << " ";
    }
    
    cout << endl;
    
    s.pop();
    
	return 0;
}

/*

Input:
5
1 2 3 4 5

Output:
Stack Contents: 5 <= 4 <= 3 <= 2 <= 1 <= 
Popping stack: 5 4 3 2 1 
Stack empty

*/
