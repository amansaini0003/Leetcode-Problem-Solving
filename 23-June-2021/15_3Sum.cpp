/* Problem Link: https://leetcode.com/problems/3sum/
    Approach: Using Two pointer 
    T.C = O(n^2) + O(nlogn)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v(3);
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<=n-3; i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                int low = i+1, high = n-1;
                while(low<high){
                    if(nums[i]+nums[low]+nums[high] == 0){
                        v[0] = nums[i]; 
                        v[1] = nums[low];
                        v[2] = nums[high];
                        res.push_back(v);
                        
                        while(low<high && nums[low]==nums[low+1])low++;
                        while(low<high && nums[high]==nums[high-1])high--;

                        low++; high--;
                    }
                    else if(nums[i]+nums[low]+nums[high] < 0)
                        low++;
                    else
                        high--;
                }
            }
        }
        
        return res;
    }
};