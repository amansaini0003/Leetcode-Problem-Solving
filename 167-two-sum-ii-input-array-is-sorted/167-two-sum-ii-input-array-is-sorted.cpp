class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
        
        int low = 0, high = nums.size()-1;
        
        while(low < high) {
            if(nums[low] + nums[high] == target) {
                indices.push_back(low+1);
                indices.push_back(high+1);
                return indices;
            } else if (nums[low] + nums[high] < target){
                low++;
            } else {
                high--;
            }
        }
        
        return indices;
    }
};