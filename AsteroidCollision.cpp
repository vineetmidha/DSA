// https://leetcode.com/problems/asteroid-collision/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        if (asteroids.size() == 1){
            return asteroids;
        }
        
        vector<int> stack;
        
        stack.push_back(asteroids[0]);
        
        for (int i=1; i<asteroids.size(); i++){
            
            if (asteroids[i] > 0){
                stack.push_back(asteroids[i]);
                continue;
            } 
            
            // asteroid is negative
            
            int top;
            bool flag = true;
            
            while (stack.size() > 0){
                top = stack.back();

                if (top < 0){     // stack top is negative
                    stack.push_back(asteroids[i]);
                    break;
                }
                
                // stack top is positive
                
                if (top > abs(asteroids[i])){
                    flag = false;
                    break;
                } else if (top == abs(asteroids[i])){
                    stack.pop_back();
                    flag = false;
                    break;
                } 
                
                stack.pop_back();
            }
            if (stack.size()==0 and flag){
                stack.push_back(asteroids[i]);
            }
        }
        
        return stack;
    }
};

/*

[5,10,-5] => [5,10]
[8,-8] = []
[10,2,-5] = [10]
[-2,-1,1,2] => []
[-2,-2,1,-2] => [-2,-2,1,-2]
[-2,-2,1,-1] => [-2,-2]
[1,-2,-2,-2] => [-2,-2,-2]

*/

