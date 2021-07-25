// Problem Link: https://leetcode.com/problems/partition-array-into-disjoint-intervals/


class Solution { 

public:
    int partitionDisjoint(vector<int>& nums) {
        int leftSize = 1, n=nums.size();
        int maxLeft = nums[0], mx = nums[0];
        
        for(int i=1; i<n-1; i++){
            if(nums[i] < maxLeft){
                leftSize = i+1;
                maxLeft = mx;
            }
              mx = max(mx,nums[i]);
        }
        return leftSize;
    }
};