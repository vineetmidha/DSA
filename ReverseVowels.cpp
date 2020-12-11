// https://leetcode.com/problems/reverse-vowels-of-a-string/

class Solution {
public:
	bool isVowel (char ch) {
		string s = "aeiouAEIOU";
		
		for (auto c: s) {
			if (c == ch) return true;
		}
		
		return false;
	}
	
    string reverseVowels(string s) {
    	int left = 0;
    	int right = s.length() - 1;
    	
    	while (left < right) {
    		
    		// First loop from left side of string 
    		// till we find a vowel
    		
    		while (left < right && !isVowel(s[left]))
				left++;

    		// Second loop from right side of string 
    		// till we find a vowel
    		
    		while (left < right && !isVowel(s[right]))
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
