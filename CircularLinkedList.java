// Single Circular Linked List Operations

// Insertion at End, Insertion at Beginning, Display

import java.util.*;
import java.lang.*;
import java.io.*;

class Node {
    int info;
    Node next;
    
    Node(int info){
        this.info = info;
        this.next = null;
    }

    Node(int info, Node next){
        this.info = info;
        this.next = next;
    }
}

class CircularLinkedList {
    Node tail;
    
    CircularLinkedList() {
        tail = null;
    }
    
    void insertAtStart(int info){
        Node fresh = new Node(info);
        
        // First Node
        
        if (tail == null){
            tail = fresh;
            fresh.next = fresh;
            return;
        }
        
        // Subsequent nodes
        
        fresh.next = tail.next;
        tail.next = fresh;
    }

    void insertAtEnd(int info){
        Node fresh = new Node(info);
        
        // First Node
        
        if (tail == null){
            tail = fresh;
            fresh.next = fresh;
            return;
        }
        
        // Subsequent nodes
        
        fresh.next = tail.next;
        tail.next = fresh;
        tail = fresh;
    }
    
    void display(){
        Node temp = tail.next;

        do{
            System.out.print(temp.info + "==>");
            temp = temp.next;
        }while (temp != tail.next);
        
        System.out.println();
    }
}

class Main {

  public static void main(String[] args) {
	    CircularLinkedList list1 = new CircularLinkedList();
      
      for (int i=1; i<=5; i++)
          list1.insertAtEnd(i);

      System.out.print("Insertion at end: "); 

      list1.display();

	    CircularLinkedList list2 = new CircularLinkedList();

      for (int i=1; i<=5; i++)
          list2.insertAtStart(i);

      System.out.print("Insertion at beginning: "); 

      list2.display();
  }
}

/*

Insertion at end: 1==>2==>3==>4==>5==>
Insertion at beginning: 5==>4==>3==>2==>1==>

*/
