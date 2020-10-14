// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/

/*
Algorithm:

The string must contain all binary codes of size k. 
This means that the number of distinct sub-strings should be exactly 2^k.

Example: k=2
Sub-strings: 00, 01, 10, 11

1. Using Kadane's algorithm, we can map each k-bit code to an integer index (0 to k-1).
2. Create a map of 2^k elements initialized with 0.
3. The index will be used to change map element to 1 and we will keep a count of such inversions.
4. At the end, if count == 2^k, it means the string contains all binary codes of size k.

*/

class Solution {
public:
    int getIndex(string bits){
        int index = 0;
        int power = bits.length()-1;
        
        for (int i = 0; i < bits.length(); i++){
            index += (bits.at(i)-'0') * (int) pow(2,power);
            power--;
        }
        return index;
    }
    
    bool hasAllCodes(string s, int k) {
        string bits;
        int total_bits = (int)pow(2,k);
            
        int *map = new int[total_bits];
        
        int count = 0;
        
        for (int i=0; i<s.length(); i++){
            bits.push_back(s.at(i));
            
            if (i >= k-1){
                int index = getIndex(bits);
                if (map[index] != 1){
                    map[index] = 1;
                    count++;
                }
                bits.erase(0,1);
            }
        }
        return count == int(pow(2,k));
    }
};

/*

Example 1:

Input: s = "00110110", k = 2
Output: true
Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indicies 0, 1, 3 and 2 respectively.

Example 2:

Input: s = "00110", k = 2
Output: true

Example 3:

Input: s = "0110", k = 1
Output: true
Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 

Example 4:

Input: s = "0110", k = 2
Output: false
Explanation: The binary code "00" is of length 2 and doesn't exist in the array.

Example 5:

Input: s = "0000000001011100", k = 4
Output: false

*/
