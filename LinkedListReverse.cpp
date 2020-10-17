// Reverse Singly Linked List
// Iterative - Pointer
// Iterative - Data
// Recursive - Pointer

#include <iostream>
#include <stack>

using namespace std;

class Node {
    int info;
    Node * next;
public:
    Node(int x=0, Node *link=nullptr){
        info = x;
        next = link;
    }
    
    void setNext(Node *link){
        next = link;
    }

    int setInfo(int x){
        info = x;
    }
    
    int getInfo(){
        return info;
    }
    
    Node * getNext(){
        return next;
    }
};

class LinkedList {
    Node *head;
    int length;
public:
    LinkedList(){
        head = nullptr;
        length = 0;
    }
    
    void insertAtBeg(int x){
        length++;
        
        Node * fresh = new Node(x);
        
        if (head == nullptr)
        {
            head = fresh;    
        }
        else 
        {
            fresh->setNext(head);
            head = fresh;
        }
    }
    
    void display()
    {
        Node * temp = head;
        while (temp != nullptr){
            cout << temp->getInfo() << " ";
            temp = temp->getNext();
        }
        cout << endl;
    }

    void reverseListDataIterative (){
        int start, last = length;
        Node * temp = head;
        for (start = 1; start < last; start++){
            Node * current = temp;
    
            for (int cur = start; cur < last; cur++) {
                current = current->getNext();
            }
    
            int t = temp->getInfo();
            temp->setInfo(current->getInfo());
            current->setInfo(t);
            
            temp = temp->getNext();
            last--;
        } 
    }
    
    void reverseIterative()
    {
        Node * current = head;
        Node * next = nullptr;
        Node * prev = nullptr;
        
        while (current != nullptr)
        {
            next = current->getNext();  // next = current->next;
            current->setNext(prev);     // current->next = prev;
            prev = current;
            current = next;
        }
        
        head = prev;
    }
    
    void reverseRecursive(){
        head = reverseHelper(head);
    }
    
    Node * reverseHelper(Node * head){
        if (head == nullptr || head->getNext() == nullptr) 
            return head;
        
        Node * smallHead = reverseHelper(head->getNext());

        head->getNext()->setNext(head);   // head->next->next = head;
        
        head->setNext(nullptr);
        
        return smallHead;
    }
}; 

int main(){
    LinkedList list1;
    
    list1.insertAtBeg(1);
    list1.insertAtBeg(2);
    list1.insertAtBeg(3);
    list1.insertAtBeg(4);
    list1.insertAtBeg(5);

    cout << "Original List: ";
    list1.display();
    
    list1.reverseIterative();
    
    cout << "Reversed List (Iterative-POINTER): ";
    list1.display();

    list1.reverseListDataIterative();

    cout << "Reversed List (Iterative-DATA): ";
    list1.display();
    
    list1.reverseRecursive();
    cout << "Reversed List (Recursive-POINTER): ";
    list1.display();    

}

/*

Original List: 5 4 3 2 1 
Reversed List (Iterative-POINTER): 1 2 3 4 5 
Reversed List (Iterative-DATA): 5 4 3 2 1 
Reversed List (Recursive-POINTER): 1 2 3 4 5 

*/
