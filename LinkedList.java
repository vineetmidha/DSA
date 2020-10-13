// Single Linked List operations

// Creation, Display, Find nth node, Find Middle Node

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

class LinkedList {
    Node head;
    
    LinkedList() {
        head = null;
    }
    
    void insertAtEnd(int info){
        Node fresh = new Node(info);
        
        // First Node
        
        if (head == null){
            head = fresh;
            return;
        }
        
        // Subsequent nodes
        
        Node temp = head;

        while (temp.next != null){
            temp = temp.next;
        }
        
        temp.next = fresh;
    }
    
    int getLength(){
      if (head == null){
        return 0;
      }

      int length = 0;

      Node temp = head;

      while (temp != null){
        length++;
        temp = temp.next;
      }

      return length;
    }

    Node nthNode(int n){

      Node fast = head;
      int count = 0;

      while (count < n && fast != null){
        fast = fast.next;
        count++;
      }

      Node slow = head;

      while (fast != null){
        slow = slow.next;
        fast = fast.next;
      }

      return slow;
    }

    Node middleNode(){

      Node fast = head;
      Node slow = head;

      while (fast != null && fast.next != null){
        slow = slow.next;
        fast = fast.next.next;
      }

      return slow;
    }

    void display(){
        Node temp = head;

        while (temp != null){
            System.out.print(temp.info + "==>");
            temp = temp.next;
        }
        
        System.out.println();
    }
}

class Main {

  public static LinkedList createList(){

    LinkedList list = new LinkedList();

    for (int i=1; i<=11; i++)    
        list.insertAtEnd(i);
    
    return list;
  }


  public static void main(String[] args) {
	    LinkedList list = createList();
	    
      list.display();

      Node temp = list.nthNode(4);

      System.out.println(temp.info);      

      temp = list.middleNode();

      System.out.println(temp.info);
  }
}
