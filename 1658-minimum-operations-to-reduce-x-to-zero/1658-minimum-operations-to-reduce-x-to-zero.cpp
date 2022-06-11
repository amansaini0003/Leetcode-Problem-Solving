class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int low = 0, high = 0;
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int res = INT_MAX;
        
        while(low <= high) {
            if(sum >= x){
                if(sum == x){
                    res = min(res, low - high + n);
                }
                if(high < n){
                    sum -= nums[high];
                    high++;
                }
                else
                    break;
                
            } else{
                sum += nums[low];
                low++;
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};