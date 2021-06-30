/* Problem Link : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

    Approach 1 : Using Linear Search
            T.C = O(n)
    Approach 2: Using Binary Search
            T.C = 3 * O(logn) == O(logn)
*/

class Solution {

public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        int mid;
        
        while(low<=high){
            mid = low + (high-low)/2;
            int prev = (mid-1+n)%n;
            int next = (mid+1)%n;

            if(nums[low] <= nums[high])
                return nums[low];
            else if(nums[prev] > nums[mid] && nums[mid] < nums[next])
                break;
            
            else if(nums[mid] > nums[high])
                low = mid+1;
            else
                high = mid-1;
        }
       
        return nums[mid];
    }
};