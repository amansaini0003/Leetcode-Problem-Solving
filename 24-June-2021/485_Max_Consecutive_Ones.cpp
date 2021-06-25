/* Problem Link :https://leetcode.com/problems/max-consecutive-ones/
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currStreak = 0, maxStreak = 0;
    
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                currStreak = 0;
            }
            else{
                currStreak++;
                maxStreak = max(maxStreak, currStreak);
            }
        }
        return maxStreak;
    }
};