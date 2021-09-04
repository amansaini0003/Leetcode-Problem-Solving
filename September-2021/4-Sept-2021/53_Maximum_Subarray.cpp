class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxTillNow = INT_MIN, currSum = 0;
        
        for(int i=0; i<nums.size(); i++){
            currSum += nums[i];
            if(currSum > maxTillNow)
                maxTillNow = currSum;
            if(currSum < 0){
                currSum = 0;
            }
        }
        
        return maxTillNow;
    }
};