// Middle Node of the Linked List

// https://leetcode.com/problems/middle-of-the-linked-list/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head->next == NULL){
            return head;
        }
        
        ListNode * slow = head;
        ListNode * fast = head;
        
        while (fast != NULL and fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};

/*

Input: [1,2,3,4,5]
Output: 3

Input: [1,2,3,4,5,6]
Output: 4 

*/
