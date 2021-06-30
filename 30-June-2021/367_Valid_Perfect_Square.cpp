// Problem Link : https://leetcode.com/problems/valid-perfect-square/

// Approach 1: Using Binary Search

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long low = 1, high = num;
        
        while(low<=high){
            long long mid = low + (high - low)/2;

            if(mid*mid == num)
                return true;
            else if(mid*mid < num)
                low = mid+1;
            else
                high = mid-1;
        }
        
        return false;
    }
};



// Approach 2 : Newton Method

class Solution {
public:
    
    // Newton Method
    
    bool isPerfectSquare(int num) {
        long r = num;
        while(r*r > num){
            r = (r + (num/r))/2;
        }
        if(r*r == num)
            return true;
        return false;
    }
};

