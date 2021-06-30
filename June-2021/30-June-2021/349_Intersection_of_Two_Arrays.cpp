// Problem Link : https://leetcode.com/problems/intersection-of-two-arrays/

class Solution {
public:
    
    bool isExist(vector<int> &nums, int key){
        int low = 0, high = nums.size()-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(nums[mid] == key)
                return true;
            else if(key > nums[mid])
                low = mid+1;
            else
                high = mid-1;
        }
        return false;
    }
    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        for(int i=0; i<nums1.size(); i++){
            if(i>0 && nums1[i]==nums1[i-1])continue;
            
            if(isExist(nums2, nums1[i]))
                v.push_back(nums1[i]);
        }
        
        return v;
    }
};