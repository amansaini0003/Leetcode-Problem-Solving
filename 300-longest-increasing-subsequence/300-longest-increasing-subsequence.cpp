class Solution {
private:
    int t[2501][2501];
    
    int lis(int idx, int prev_idx, vector<int> &nums){
        if(idx == nums.size())
            return 0;
    
        if(t[idx][prev_idx + 1] != -1)
            return t[idx][prev_idx + 1];
        
        int not_take = lis(idx+1, prev_idx, nums);
        int take = INT_MIN;
        if(prev_idx == -1 || nums[prev_idx] < nums[idx]){
            take = 1 + lis(idx+1, idx, nums);
        }
        return t[idx][prev_idx+1] = max(take, not_take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        int prev_idx = -1;
        int idx = 0;
        int ans = lis(idx, prev_idx, nums);
        
        return ans;
    }
};