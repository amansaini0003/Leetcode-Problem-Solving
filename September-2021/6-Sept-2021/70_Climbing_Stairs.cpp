class Solution {
public:
    
    int t[50];
    
    int noOfWays(int i, int n){
        if(i==n)
            return 1;
        if(i>n)
            return 0;
        if(t[i]!=-1)
            return t[i];
        t[i] = noOfWays(i+1, n) + noOfWays(i+2,n);
        return t[i];
    }
        
    int climbStairs(int n) {
        memset(t, -1, sizeof(t));
        int i=0;
        int totalWays = noOfWays(0,n);
        return totalWays;
    }
};