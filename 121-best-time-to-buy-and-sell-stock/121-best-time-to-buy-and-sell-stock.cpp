class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int mn = prices[0], mx = prices[0];
        for(int i=1; i<prices.size(); i++) {
            int profit = prices[i] - mn;
            mn = min(prices[i], mn);
            maxProfit = max(profit, maxProfit);
        }
        return maxProfit;
    }
};