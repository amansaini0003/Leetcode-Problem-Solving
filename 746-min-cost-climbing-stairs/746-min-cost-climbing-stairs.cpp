class Solution {
private:
    int t[1002]; 
    int getCost(int idx, vector<int> &cost, int t[]) {
        if(idx >= cost.size()) {
            return 0;
        }
        
        if(t[idx] != -1)
            return t[idx];
        
        return t[idx] = cost[idx] + min(getCost(idx+1, cost, t), getCost(idx+2, cost, t));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        memset(t, -1, sizeof(t));
        
        int ans = min(getCost(0, cost, t), getCost(1, cost, t));
        return ans;
    }
};