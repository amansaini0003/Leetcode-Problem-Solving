/* Problem Link : https://leetcode.com/problems/single-element-in-a-sorted-array/
    
    Approach 1 : Using xor or Liner Scan
                T.C = O(n)
                S.C = O(1)
    Approach 2 : Using Binary Search
                T.C = O(logn)
                S.C = O(1)
*/




class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        int low = 0, high = n-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(mid-1 >= 0 && mid+1 < n){
                if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
                    return nums[mid];
                else if(nums[mid] == nums[mid-1]){
                    if (mid & 1)
                         low = mid+1;
                    else
                        high = mid-1;
                }
                else if(nums[mid]==nums[mid+1]){
                    if(mid % 2 == 0)
                        low = mid+1;
                    else
                        high = mid-1;
                }
                    
            }
            else if(mid==0 && nums[mid] != nums[mid+1])
                return nums[mid];
            else 
                return nums[n-1];
        }
           
        return -1;
    }
};