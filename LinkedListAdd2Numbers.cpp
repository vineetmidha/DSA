// https://leetcode.com/problems/add-two-numbers/

/*
You are given two non-empty linked lists representing two non-negative integers.

The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

// My solution. Scroll down for Striver's solution.

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * t1 = l1;
        ListNode * t2 = l2;
        
        ListNode * head = NULL;
        ListNode * tail = NULL;
        
        int carry = 0;
        
        while (t1 != NULL and t2 != NULL){
            int result = t1->val + t2->val + carry;
            
            ListNode * fresh = new ListNode(result%10);
            
            carry = result / 10;
            
            if (head == NULL){
                head = fresh;
                tail = fresh;
            } else {
                tail->next = fresh;
                tail = fresh;
            }
            
            t1 = t1->next;
            t2 = t2->next;
        }
        
        while (t1 != NULL){
            int result = t1->val + carry;
            
            ListNode * fresh = new ListNode(result%10);
            
            carry = result / 10;

            if (head == NULL){
                head = fresh;
                tail = fresh;
            } else {
                tail->next = fresh;
                tail = fresh;
            }
            
            t1 = t1->next;
        }
        
        while (t2 != NULL){
            int result = t2->val + carry;
            
            ListNode * fresh = new ListNode(result%10);
            
            carry = result / 10;
            
            if (head == NULL){
                head = fresh;
                tail = fresh;
            } else {
                tail->next = fresh;
                tail = fresh;
            }
            
            t2 = t2->next;
        }
        
        if (carry != 0){
            ListNode * fresh = new ListNode(carry);
            
            if (head == NULL){
                head = fresh;
                tail = fresh;
            } else {
                tail->next = fresh;
                tail = fresh;
            }            
        }
        
        return head;  
    }
};

// Striver's solution

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head = new ListNode();
        ListNode * tail = head;
        
        int carry = 0;
        
        while (l1 != NULL or l2 != NULL or carry != 0){
            int sum = 0;
            
            if (l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            
            sum += carry;
            carry = sum / 10;
                
            ListNode * fresh = new ListNode(sum % 10);
            
            tail->next = fresh;
            tail = tail->next;            
        }
        
        return head->next;  
    }
};
