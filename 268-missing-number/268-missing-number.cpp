class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total_sum = (n*(n+1))/2;
        
        for(int &i: nums){
            total_sum -= i;
        }
        return total_sum;
    }
};