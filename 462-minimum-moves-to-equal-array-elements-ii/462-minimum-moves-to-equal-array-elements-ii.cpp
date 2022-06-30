class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int i=0, j = nums.size()-1;
        sort(nums.begin(), nums.end());
        
        int count = 0;
        while(i < j) {
            count += nums[j] - nums[i];
            i++;
            j--;
        }
        return count;
    }
};