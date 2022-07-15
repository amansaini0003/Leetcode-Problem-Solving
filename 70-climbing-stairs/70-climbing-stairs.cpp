class Solution {
private: 
    int t[46];
    int countWaysToReachTop(int idx , int n) {
        if(idx >= n)
            return 1;
        if(t[idx] != -1)
            return t[idx];
        return t[idx] = countWaysToReachTop(idx+1, n) + countWaysToReachTop(idx+2, n);
    }
    
public:
    int climbStairs(int n) {
        memset(t, -1, sizeof(t));
        int ways = countWaysToReachTop(1, n) ;
        return ways;
    }
};