// Fast Power : https://leetcode.com/problems/powx-n/

// Iterative

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long nn = n;
        
        if (nn < 0) nn = -nn;
        
        while (nn > 0) {
            if (nn % 2 == 0){
                x = x * x;
                nn /= 2;
            } else {
                ans = ans * x;
                nn--;
            }
        }
        
        if (n < 0)
            ans = (double) 1.0 / (double) ans;
        
        return ans;
    }
};


// Recursive

class Solution {
public:
    double myPow(double x, long n) {
        if (n == 0)
            return 1.0;
        
        if (n > 0) {
            double ans = myPow(x, n/2);
            if (n % 2 == 0)
                return ans * ans;
            else
                return x * ans * ans;
        }
        else {
            return 1 / myPow(x, -n);
        }
    }
};

