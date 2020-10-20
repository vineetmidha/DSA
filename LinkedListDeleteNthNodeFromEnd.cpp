// Delete nth node from end of a linked list

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

// My Solution

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == NULL) {
            return NULL;   
        }
        
        ListNode * slow = head;
        ListNode * fast = head;
        ListNode * prev;
        
        for (int i = 1; i <= n; i++){
            fast = fast->next;
        }

        while (fast != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        
        if (slow == head){
            head = head->next;
        } else {
            if (slow->next == NULL){
                prev->next = NULL;
            } else {
                prev->next = prev->next->next;            
            }
        }        
        
        delete slow;
        return head;
    }
};

// Solution by Striver: https://www.youtube.com/watch?v=Lhu3MsXZy-Q&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=27

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * start = new ListNode();
        start->next = head;
        
        ListNode * slow = start;
        ListNode * fast = start;
        
        for (int i = 1; i <= n; i++){
            fast = fast->next;
        }

        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        
        slow->next = slow->next->next; 
        
        return start->next;
    }
};

/*

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Input: head = [1], n = 1
Output: []

Input: head = [1,2], n = 1
Output: [1]

*/
