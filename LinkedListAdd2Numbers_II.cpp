// https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/564/week-1-november-1st-november-7th/3522/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLinkedList(ListNode *head){
        if (head == nullptr) return head;
        
        ListNode * current = head;
        ListNode * prev = nullptr;
        ListNode * aglaCurrent = nullptr;
        
        while (current != nullptr){
            aglaCurrent = current->next;
            current->next = prev;
            prev = current;
            current = aglaCurrent;
        }
        
        return prev;
    }
    
    ListNode* addTwo(ListNode* l1, ListNode* l2) {
        ListNode * head = new ListNode();
        ListNode * tail = head;
        
        int carry = 0;
        
        while (l1 != nullptr or l2 != NULL or carry != 0){
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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr;
        
        l1 = reverseLinkedList(l1);
        l2 = reverseLinkedList(l2);
        
        head = addTwo(l1,l2);
        
        head = reverseLinkedList(head);
        
        return head;
    }
};
