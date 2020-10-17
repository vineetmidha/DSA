// Check if a singly linked list is a palindrome

// Algorithm: 

/*
  1.  Push all nodes of the linked list onto a stack. Now, the list is saved onto stack in reversed order. 
  2.  Pop topmost node of the stack.
  3.  Compare it with the first node of the link list.
  4.  Repeat steps 2, 3 for all the nodes of the list and stack.
  5.  If any one of the nodes mismatches, list is not a palindrome otherwise it is a palindrome.
*/

#include <iostream>
#include <stack>

using namespace std;

class Node 
{
    int info;
    Node * next;
public:
    Node(int x = 0, Node *link = nullptr)
    {
        info = x;
        next = link;
    }
    
    void setNext(Node *link)
    {
        next = link;
    }
    
    int getInfo()
    {
        return info;
    }
    
    Node * getNext()
    {
        return next;
    }
};

class LinkedList 
{
    Node *head;
public:
    LinkedList()
    {
        head = nullptr;
    }
    
    void insertAtBeg(int x)
    {
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
        while (temp != nullptr)
        {
            cout << temp->getInfo() << " ";
            temp = temp->getNext();
        }
        cout << endl;
    }
    
    bool isPalindrome()
    {
        stack<Node> s;
        
        Node * temp = head;

        // copy all nodes to stack
        
        while (temp != nullptr)
        {
            s.push(*temp);
            temp = temp->getNext();
        }
        
        // check node at the top is equal to first node of list and so on 
        
        temp = head;
        
        while (temp != nullptr)
        {
            Node top = s.top();
            
            if (temp->getInfo() != top.getInfo())
            {
                return false;    
            }

            s.pop();
            
            temp = temp->getNext();
        }
        
        return true;
    }
}; 

int main()
{
    LinkedList list1;
    
    list1.insertAtBeg(1);
    list1.insertAtBeg(2);
    list1.insertAtBeg(2);
    list1.insertAtBeg(1);
    list1.insertAtBeg(1);

    cout << "List-1: ";
    list1.display();
    
    if (list1.isPalindrome())
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    cout << endl;
    
    LinkedList list2;
    
    list2.insertAtBeg(1);
    list2.insertAtBeg(2);
    list2.insertAtBeg(2);
    list2.insertAtBeg(1);

    cout << "List-2: ";
    list2.display();
    
    if (list2.isPalindrome())
        cout <<"Palindrome" << endl;
    else
        cout <<"Not Palindrome" << endl;
}

/*

List-1: 1 1 2 2 1 
Not Palindrome

List-2: 1 2 2 1 
Palindrome

*/
