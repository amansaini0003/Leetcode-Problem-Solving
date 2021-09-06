class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prevMinPrice = prices[0];
        int profit = 0;
        
        for(int i=1; i<prices.size(); i++){
            profit = max(profit, prices[i]-prevMinPrice);
            prevMinPrice = min(prevMinPrice, prices[i]);
        }
        return profit;
    }
};