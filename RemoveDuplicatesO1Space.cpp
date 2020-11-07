// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        if (v.size()==0){
            return 0;
        }
        
        sort(v.begin(), v.end());
        
        int prev = v[0];
        int count = 1;

        for (int i=1; i<v.size(); i++){
            int current = v[i];
            if (current != prev){
                v[count] = current;
                prev = current;
                count++;
            }
        }
        return count;
    }
};

