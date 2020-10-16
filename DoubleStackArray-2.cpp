// Implement double stack using single array - single push/pop for both the stacks

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
    void push(int stack, int x){
        int *ptr_top = 0;
        int limit;

        if (stack == 1){
            ptr_top = &top1;
            limit = size/2-1;
        } else {
            ptr_top = &top2;
            limit = size-1;
        }

        if (*ptr_top == limit){
            cout << "Stack-" << stack << " full" << endl;
            return;
        }

        data[++*ptr_top] = x;
    }
    void pop(int stack){
        int *ptr_top = 0;

        if (stack == 1){
            ptr_top = & top1;
        } else {
            ptr_top = & top2;
        }

        if (isEmpty(stack)){
            cout << "Stack-" << stack << " empty" << endl;
            return;
        }
        --*ptr_top;
    }
    bool isEmpty(int stack){
        if (stack == 1)
            return top1 == -1;
        else
            return top2 == size/2-1;
    }
    int peek(int stack){
        if (stack == 1)
            return isEmpty(stack) ? -1 : data[top1];
        else
            return isEmpty(stack) ? -1 : data[top2];
    }
};

int main() {
    DoubleStack s(5);

    s.push(1,10);
    s.push(1,20);
    s.push(1,30);
    s.push(1,30);

    cout << s.peek(1) << endl;

    while (not s.isEmpty(1)){
        cout << "Popped: " << s.peek(1) << endl;
        s.pop(1);
    }

    s.pop(1);

    s.push(2,40);
    s.push(2,50);
    s.push(2,60);
    s.push(2,70);

    cout << s.peek(2) << endl;

    while (not s.isEmpty(2)){
        cout << "Popped: " << s.peek(2) << endl;
        s.pop(2);
    }

    s.pop(2);

    cout << s.peek(2);

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
