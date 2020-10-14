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
    // O(n^2) solution
    
    vector<int> nextLargerNodes(ListNode* head) {
        auto itr = head;
        
        vector<int> ans;
        
        while (itr != nullptr) {
            auto innerItr = itr->next;
            bool flag = false;
            
            while (innerItr != nullptr) {
                if (innerItr->val > itr->val) {
                    flag = true;
                    ans.emplace_back(innerItr->val);
                    break;
                }                
                innerItr = innerItr->next;
            }
            
            if (!flag){
                ans.emplace_back(0);
            }
            
            itr = itr->next;
        }
        
        return ans;
    }
    
    //  O(n) solution using stack
    
    /*
    Algorithm:
    
    1.  Copy the data from the linked list to a vector because we need indexes.
    2.  Declare a stack to hold the indexes
    3.  Push the first index (0) onto stack
    4.  For each value in the vector:
        4.1 Do the following till the stack is not empty and the value is more than the value at topmost index in the stack
            4.1.1 The value (from the values vector) at the index (which is saved at the top of stack) is saved at the same index in the answer vector.
            4.1.2 Pop the stack
            4.1.3 Push the current index onto stack
        4.2 If the value <= the value at the index in the stack:
            4.2.1 Push the current index onto stack
    5.  Return the answer vector
    
    */
    
    vector<int> nextLargerNodes(ListNode* head) {
        auto itr = head;
        
        vector<int> values;
        
        // copy all the values from linked list into a vector
        
        while (itr != nullptr) {
            values.emplace_back(itr->val);
            itr = itr->next;
        }
        
        // create vector to save answer
        
        vector<int> ans (values.size(), 0);
        
        // create stack to hold indexes
        
        stack<int> stk;
        
        // push first index
        
        stk.push(0);
        
        // Run the loop till the end of vector values to find nextLarger value for each of its elements
        
        for (int i = 1; i < values.size(); i++) {
            
            // Run loop till stack is not empty and element of values vector is greater than the value at the index at the top of stack 
            
            while (not stk.empty() && values[i] > values[stk.top()]) {
                ans[stk.top()] = values[i];             // save the value in answer vector at top most index stored in stack
                stk.pop();                              // pop the top most element of stack
            }
            stk.push(i);                                // push the current index onto stack
        }
        
        return ans;
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
