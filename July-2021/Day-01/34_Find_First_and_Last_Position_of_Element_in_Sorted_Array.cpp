// Problem Link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    
    int lowerBound(vector<int> &nums, int key){
        int low = 0, high = nums.size()-1;
        
        while(low<high){
            int mid = low + (high-low)/2;
             if(key <= nums[mid])
                high = mid;
            else
                low = mid+1;
        }
        if(nums[high] != key)return -1;
        return high;
    }
    
    int upperBound(vector<int> &nums, int key){
         int low = 0, high = nums.size()-1, ub = 0;
        
        while(low<=high){
            int mid = low + (high-low)/2;
             if(key < nums[mid])
                high = mid-1;
            else{
                low = mid+1;
                ub = mid;
            }
        }
          if(nums[ub] != key)return -1;
        return ub;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        if(nums.size()==0)return {-1,-1};
        
        int lb = lowerBound(nums, target);
        int ub = upperBound(nums, target);
        
        v.push_back(lb);
        v.push_back(ub);
        
        return v;
    }
};