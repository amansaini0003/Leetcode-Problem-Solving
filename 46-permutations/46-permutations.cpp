class Solution {
private: 
    vector<vector<int>> allPermutations;
    
    void permuteUtil(int idx, vector<int> &nums) {
        if(idx == nums.size()) {
            allPermutations.push_back(nums);
            return;
        }
     
        for(int i=idx; i<nums.size(); i++) {
            swap(nums[i], nums[idx]);
            permuteUtil(idx+1, nums);
            swap(nums[i], nums[idx]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int idx = 0;
        permuteUtil(idx, nums);
        
        return allPermutations;
    }
};