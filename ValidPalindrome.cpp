// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        
        int i = 0;
        int j = s.size()-1;

        while (i < j)
        {
            if (!isalnum(s[i])){
                i++;
                continue;                
            }

            if (!isalnum(s[j])){
                j--;
                continue;                
            }
            
            char x = tolower(s[i]);
            char y = tolower(s[j]);
            
            if (x != y)
                return false;
            
            i++;
            j--;
        }
        
        return true;
    }
};
