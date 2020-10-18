// https://leetcode.com/problems/two-sum/submissions/

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] result = new int[2];
        
        Map<Integer,Integer> map = new HashMap<>();
        
        for (int i = 0; i < nums.length; i++){
            if (map.containsKey(target-nums[i])){
                result[0] = i;
                result[1] = map.get(target-nums[i]);
                return result;
            }
            map.put(nums[i], i);
        }
        
        return result;
    }
}
