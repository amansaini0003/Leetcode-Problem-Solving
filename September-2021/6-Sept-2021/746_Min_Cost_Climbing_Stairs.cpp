// Approach 1:
class Solution {
public:
    int t[1001];
    
    int solve(int i, int n, vector<int>& cost){
        if(i==n || i==n-1)
            return cost[i];
        
        if(t[i]!=-1)
            return t[i];
        
        int c1 = cost[i] + solve(i+1, n, cost);
        int c2 = cost[i] + solve(i+2, n, cost);
        
        t[i] = min(c1, c2);
        return t[i];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size()-1;
        memset(t, -1, sizeof(t));
        
        int startFromZero = solve(0, n, cost);
        int startFromOne = solve(1, n, cost);
        
        int minCost = min(startFromZero, startFromOne);
        
        return minCost;
    }
};


// Approach 2: Optimization of above
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int t[n+1];
        
        t[0] = cost[0];
        t[1] = cost[1];
        
        for(int i=2; i<n; i++){
            t[i] = cost[i] + min(t[i-1], t[i-2]);
        }
        return min(t[n-1], t[n-2]);
    }
};


// Approach 3: Optimization of above
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        int a = cost[0];
        int b = cost[1], c;
        
        if(n<=2)return min(a,b);
        
        for(int i=2; i<n; i++){
            c = cost[i] + min(b, a);
            a = b;
            b = c;
        }
        return min(c, a);
    }
};