
// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

class Solution {
public:
    
    int countNegatives(vector<vector<int>>& grid) {
        
        int count = 0;
        
        for (int i=0; i<grid.size(); i++){
            int index = getNegativeIndex(grid[i]);
            
            if (index != -1){
                count += grid[i].size() - index;
            }
        }
        
        return count;
    }
    
    // Find out lower bound of negative number in a row
    
    int getNegativeIndex(vector<int> row) {
        int start = 0;
        int end = row.size() - 1;
        
        while (start <= end){
            int mid = (start + end) / 2;
            
            if (row[mid] >= 0)
                start = mid + 1;

            if (row[mid] < 0){          // negative found on mid
                if (mid == 0) return mid; // if mid is zero, no need to check left of mid
                
                if (row[mid-1] >= 0)  // positive number towards left of mid
                    return mid;
                
                end = mid - 1;      //  negativve number towards left of mid
            }
        }
        
        return -1;
    }
};

