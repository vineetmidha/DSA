// k-Reverse


/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */

class Node
{
    int info;
    Node next;

    Node (int x) {
        info = x;
        next = null;
    }
}

class LinkedList
{
    Node head;
    
    LinkedList(){
        head = null;
    }
    
    public void InsertAtBeg(int info){
        Node fresh = new Node (info);
        
        if (head != null){
            fresh.next = head;
        }
        
        head = fresh;
    }
    
    public void display(){
        Node current = head;
        
        while (current != null){
            System.out.print(current.info + " => ");
            current = current.next;
        }
        
        System.out.println();
    }
    
    public void display(Node start){
        Node current = start;
        
        while (current != null){
            System.out.print(current.info + " => ");
            current = current.next;
        }
        
        System.out.println();
    }

    public void reverseLinkedList(){
        if (head == null) return;
        
        Node current = head;
        Node prev = null;
        Node aglaCurrent = null;
        
        while (current != null){
            aglaCurrent = current.next;
            current.next = prev;
            prev = current;
            current = aglaCurrent;
        }
        
        head = prev;
    }
    
    public Node reverseLinkedList(Node start, Node end){
        if (start == null) return null;
        
        Node subHead = start;
        
        if (end != null)
            end.next = null;
        
        Node current = start;
        Node prev = null;
        Node aglaCurrent = null;

        while (current != null){
            aglaCurrent = current.next;
            current.next = prev;
            prev = current;
            current = aglaCurrent;
        }
        
        subHead = prev;
    
        return subHead;
    }
    
    public int getLength(){
        Node current = head;
        int count = 0;
        
        while (current != null){
            count++;
            current = current.next;
        }
        
        return count;
    }
    
    public void kReverse (int k){
        if (k <= 1){
            display();
            return;
        } else if (k > getLength()){
            k = getLength();
        } 
        
        Node start = head;
        Node end = head;
        
        Node reversedHead = null;
        Node prevStart = null;
        
        while (start != null){
            for (int i = 1; i < k && end != null; i++) {
                end = end.next;
            }

            Node newStart = null;
            
            if (end != null)
                newStart = end.next;
            
            Node subHead = reverseLinkedList(start, end);
            
            if (reversedHead == null){
                reversedHead = subHead;
            } else {
                prevStart.next = subHead;
            }
            
            prevStart = start;
            start = end = newStart;
        }
        
        head = reversedHead;
    }
}

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		LinkedList list = new LinkedList();
		
		for (int i=10; i<=100; i+=10)
    		list.InsertAtBeg(i);
    		
    	list.display();
    	
    	list.reverseLinkedList();
    	
    	list.display();
		
		int k = 50;
		list.kReverse(k);
		
		list.display();
	}
}

/*

Original List:

100 => 90 => 80 => 70 => 60 => 50 => 40 => 30 => 20 => 10 => 

k-Reversed (Where k = 3)

80 => 90 => 100 => 50 => 60 => 70 => 20 => 30 => 40 => 10 => 

k-Reversed (Where k = 4)

70 => 80 => 90 => 100 => 30 => 40 => 50 => 60 => 10 => 20 => 

*/
