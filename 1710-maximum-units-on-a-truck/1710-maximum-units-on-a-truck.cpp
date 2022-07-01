class Solution {
public:
    static bool comp(vector<int> arr1, vector<int> arr2){
        if(arr1[1] > arr2[1])
            return true;
        return false;
    }
    int maximumUnits(vector<vector<int>>& nums, int truckSize) {
        sort(nums.begin(), nums.end(), comp);
        int val = 0;
        for(int i=0; i<nums.size(); i++) {
            if(truckSize <= 0)  break;
            
            if(nums[i][0] <= truckSize){
                val += nums[i][0] * nums[i][1];
                truckSize -= nums[i][0];
            } else {
                val += truckSize * nums[i][1];
                truckSize = 0;                
            }
        }
        
        return val;
    }
};