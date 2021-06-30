/* Problem Link : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

    Approach 1 : Using Linear Search
            T.C = O(n)
    Approach 2: Using Binary Search
            T.C =  O(logn)

1) everytime check if targe == nums[mid], if so, we find it.
2) otherwise, we check if the first half is in order (i.e. nums[left]<=nums[mid]) 
   and if so, go to step 3), otherwise, the second half is in order,   go to step 4)
3) check if target in the range of [left, mid-1] (i.e. nums[left]<=target < nums[mid]), 
   if so, do search in the first half, i.e. right = mid-1; otherwise, search in the second half left = mid+1;
4) check if target in the range of [mid+1, right] (i.e. nums[mid]<target <= nums[right]), 
   if so, do search in the second half, i.e. left = mid+1; otherwise search in the first half right = mid-1;

The only difference is that due to the existence of duplicates,
 we can have nums[left] == nums[mid] and in that case,
  the first half could be out of order (i.e. NOT in the ascending order, e.g. [3 1 2 3 3 3 3]) 
 and we have to deal this case separately. In that case, it is guaranteed that nums[right] also equals to nums[mid],
  so what we can do is to check if nums[mid]== nums[left] == nums[right] before the original logic, 
  and if so, we can move left and right both towards the middle by 1. and repeat.

*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(nums[mid]==target)return true;
            
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low++; 
                high--;
            }
            else if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target < nums[mid])
                    high = mid-1;
                else
                    low = mid+1;
                    
            }
            else{
                if(nums[mid] < target && target <= nums[high])
                    low = mid+1;
                else
                    high = mid-1;
            }
        }
        return false;
    }
};