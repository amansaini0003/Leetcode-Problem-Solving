class Solution {
private: 
    int t[10002];
public:
    int coinChangeUtil(int amount, vector<int> &coins) {
        if(amount == 0) return 0;
        
        if(t[amount] != -1) 
            return t[amount];
        
        int ans = INT_MAX;    
        for(int coin : coins) {
            if(amount-coin >= 0)
                ans = min(coinChangeUtil(amount - coin, coins) + 1LL, ans + 0LL);
        }
        return t[amount] = ans;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        memset(t, -1, sizeof(t));
        
        int ans = coinChangeUtil(amount, coins);
        return ans == INT_MAX ? -1 : ans;
    }
};