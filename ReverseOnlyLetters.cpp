// https://leetcode.com/problems/reverse-only-letters/

class Solution {
public:
    string reverseOnlyLetters(string s) {
    	int left = 0;
    	int right = s.length() - 1;
    	
    	while (left < right) {
    		
    		// First loop from left side of string 
    		// till we find a letter
    		
    		while (left < right && !isalpha(s[left]))
				left++;

    		// Second loop from right side of string 
    		// till we find a letter
    		
    		while (left < right && !isalpha(s[right]))
				right--;
			
			// swap
			
    		char t = s[left];
    		s[left] = s[right];
    		s[right] = t;
							
    		left++;
    		right--;    		
    	}

    	return s;        
    }
};

