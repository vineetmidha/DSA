# https://leetcode.com/problems/next-greater-node-in-linked-list/

# O(n) solution using stack

def nextLargerNodes(nums):
    stack = [0]

    nextLargers = [0] * len(nums)
    
    for index in range(1, len(nums)):
        value = nums[index]
        
        while stack and value > nums[stack[-1]]:
            i = stack.pop()
            nextLargers[i] = value
            
        stack.append(index)

    return nextLargers

nums = [[2,7,4,3,5],[2,1,5],[1,7,5,1,9,2,5,1]]

for i in nums:
    print(nextLargerNodes(i))
    
'''

Example 1:

Input: [2,1,5]
Output: [5,5,0]

Example 2:

Input: [2,7,4,3,5]
Output: [7,0,5,5,0]

Example 3:

Input: [1,7,5,1,9,2,5,1]
Output: [7,9,9,9,0,5,0,0]

'''
