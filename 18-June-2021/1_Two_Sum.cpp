// Problem Link : https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        vector<int> idx;
        
        for(int i=0; i<nums.size(); i++){
            auto it = mp.find(target-nums[i]);
            
            if(it == mp.end())
                mp.insert({nums[i], i});
            else{
                idx.push_back(i);
                idx.push_back(it->second);
            }
        }
        return idx;
    }
};