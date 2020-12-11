// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size()==0) return 0;
        
        map<int, int> hash;
        int start = 0;
        int max_length = 0;
        
        for (int i = 0; i < s.size(); i++){            
            if (hash.find(s[i]) != hash.end()) // found
            {
                int index = hash[s[i]];
                if (index >= start){
                    max_length = max(max_length, index-start+1);
                    start = index + 1;                                    
                }
            }
            hash[s[i]] = i;
            max_length = max(max_length, i-start+1);
        }
        
        return max_length;
    }
};
