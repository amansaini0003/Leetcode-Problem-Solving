class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0, mn = nums[0];
        for(int &i: nums) {
            sum += i;
            mn = min(i, mn);
        }
        
        int moves = sum - (nums.size() * mn);
        return moves;
    }
};