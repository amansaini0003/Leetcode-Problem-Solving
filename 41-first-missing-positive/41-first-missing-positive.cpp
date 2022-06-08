class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int prev = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] <= 0)continue;
            if(i>0 && nums[i] == nums[i-1])continue;
            if(nums[i] != prev+1){
                return prev+1;
            }
            prev = nums[i];
        }
        return prev+1;
    }
};