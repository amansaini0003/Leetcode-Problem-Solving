class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> ans;
        
        for(int i=0; i<nums.size(); i++) {
            int b = target - nums[i];
            if(mp.find(b) != mp.end()) {
                ans.push_back(i);
                ans.push_back(mp[b]);
                break;
            }
            mp[nums[i]] = i;
        }
        return ans;
        
    }
};