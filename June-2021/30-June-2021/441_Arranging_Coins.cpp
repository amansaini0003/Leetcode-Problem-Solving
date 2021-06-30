// Problem Link : https://leetcode.com/problems/arranging-coins/


// Approach 1: Using Binary Search      T.C = O(logn) , S.C = O(1)

class Solution {
public:
    int arrangeCoins(int n) {
        long long int low = 1, high = INT_MAX;
        
        while(low <= high){
            long long int mid = low + (high-low)/2;
            
            long long int sumTillMid = (mid * (mid+1));
            sumTillMid /= 2;
            
            if(n == sumTillMid)
                return mid;
            else if(n < sumTillMid)
                high = mid-1;
            else
                low = low+1;
        }
        return high;
    }
};





// Approach 2: Using Math           T.C = O(1) , S.C = O(1)

class Solution {
public:
    int arrangeCoins(int n) {
        // k * k+1/2 <= n
        // add +- 1/4
        // k = sqrt(2n + 1/4) - 1/2;
        
        return int(sqrt(2* long(n) + 0.25) - 0.5);
    }
};