/* Problem Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

    Approach: Using Two pointer 
    T.C = O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        vector<int> ans;
        
        while(low<high){
            if(nums[low]+nums[high]==target){
                ans.push_back(low+1);
                ans.push_back(high+1);
                break;
            }
            else if(nums[low]+nums[high]<target)
                low++;
            else
                high--;
        }
        return ans;
    }
};