/* Problem Link : https://leetcode.com/problems/search-in-rotated-sorted-array/

    Approach 1 : Using Linear Search
            T.C = O(n)
    Approach 2: Using Binary Search
            T.C = 3 * O(logn) == O(logn)
*/
class Solution {
public:
    
    int binarySearch(vector<int> &nums, int low, int high, int target){

        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                high = mid-1;
            else
                low = mid+1;
        }
        return -1;
    }
    
    int pivotIndex(vector<int> nums){
        int n = nums.size();
        int low = 0, high = n-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            int prev = (mid-1+n)%n;
            int next = (mid+1)%n;
            
            if(nums[low] <= nums[high]) 
                return low;
            else if(nums[prev] > nums[mid] && nums[mid] < nums[next]){
                return mid;
            }
            else if(nums[mid] > nums[high])
                low = mid+1;
            else
                high = mid-1;
        }
        return low;
    }
    
    int search(vector<int>& nums, int target) {
        
        int pivot = pivotIndex(nums);
        
        int firstHalf = binarySearch(nums, 0, pivot-1, target);
        int secondHalf = binarySearch(nums, pivot, nums.size()-1, target);
        
        if(firstHalf > -1)return firstHalf;
        
        return secondHalf;
    }
};

//           l  m  h
// 4 5 6  7  0  1  2