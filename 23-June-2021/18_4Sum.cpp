/* Problem Link: https://leetcode.com/problems/4sum/
    Approach: Using Two pointer 
    T.C = O(n^3)+O(nlogn)
*/


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        
        for(int i=0; i<=n-4; i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                for(int j=i+1; j<=n-3; j++){
                    if(j==i+1 || (j>i+1 && nums[j]!=nums[j-1])){
                        int l = j+1, h=n-1;
                        while(l<h){
                            if(nums[l]+nums[h]==target-(nums[i]+nums[j])){
                                res.push_back(vector<int> {nums[i], nums[j], nums[l], nums[h]});
                                while(l<h && (nums[l]==nums[l+1]))l++;
                                while(l<h && (nums[h]==nums[h-1]))h--;
                                
                                l++;
                                h--;
                            }
                            else if(nums[l]+nums[h] < target-(nums[i]+nums[j]))
                                l++;
                            else
                                h--;
                        }
                    }
                }
            }
        }
        
        return res;
    }
};