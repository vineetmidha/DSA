// Implement two stacks with one array

#include <iostream>
using namespace std;

class DoubleStack {
    int *data;
    int size; 
    int top1, top2;
    
public:
    DoubleStack (int elements = 5){
        size = elements;
        
        top1 = -1;
        top2 = size/2-1;
        
        data = new int[size];
    }
    void push1(int x){
        if (top1 == size/2-1){
            cout << "Stack-1 full" << endl;
            return;
        }
        
        data[++top1] = x;
    }
    void pop1(){
        if (isEmpty1()){
            cout << "Stack-1 empty" << endl;
            return;
        }
        top1--;
    }
    bool isEmpty1(){
        return top1 == -1;
    }
    int peek1(){
        return isEmpty1() ? -1 : data[top1];
    }
    void push2(int x){
        if (top2 == size-1){
            cout << "Stack-2 full" << endl;
            return;
        }
        
        data[++top2] = x;
    }
    void pop2(){
        if (isEmpty2()){
            cout << "Stack-2 empty" << endl;
            return;
        }
        top2--;
    }
    bool isEmpty2(){
        return top2 == size/2-1;
    }
    int peek2(){
        return isEmpty2() ? -1 : data[top2];
    }
};

int main() {
    DoubleStack s(5);

    s.push1(10);
    s.push1(20);
    s.push1(30);
    s.push1(30);

    cout << s.peek1() << endl;
    
    while (not s.isEmpty1()){
        cout << "Popped: " << s.peek1() << endl;
        s.pop1();
    }

    s.pop1();
    
    s.push2(40);
    s.push2(50);
    s.push2(60);
    s.push2(70);

    cout << s.peek2() << endl;
    
    while (not s.isEmpty2()){
        cout << "Popped: " << s.peek2() << endl;
        s.pop2();
    }

    s.pop2();

    cout << s.peek2();
        
	return 0;
}

/*

Stack-1 full
Stack-1 full
20
Popped: 20
Popped: 10
Stack-1 empty
Stack-2 full
60
Popped: 60
Popped: 50
Popped: 40
Stack-2 empty
-1


*/
