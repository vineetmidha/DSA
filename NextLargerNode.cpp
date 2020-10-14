// https://leetcode.com/problems/next-greater-node-in-linked-list/

// O(n^2) solution

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
    vector<int> nextLargerNodes(ListNode* head) {
        auto itr = head;
        
        vector<int> largerNums;
        
        while (itr != nullptr) {
            auto innerItr = itr->next;
            bool flag = false;
            
            while (innerItr != nullptr) {
                if (innerItr->val > itr->val) {
                    flag = true;
                    largerNums.push_back(innerItr->val);
                    break;
                }                
                innerItr = innerItr->next;
            }
            
            if (!flag){
                largerNums.push_back(0);
            }
            
            itr = itr->next;
        }
        
        return largerNums;
    }
};

/*

Example 1:

Input: [2,1,5]
Output: [5,5,0]

Example 2:

Input: [2,7,4,3,5]
Output: [7,0,5,5,0]

Example 3:

Input: [1,7,5,1,9,2,5,1]
Output: [7,9,9,9,0,5,0,0]

*/
