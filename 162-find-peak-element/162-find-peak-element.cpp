class Solution {
//          [1,2,1,3,5,6,4]
private: 
    int search(vector<int> &nums){
        int n = nums.size();
        int low = 0, high = n-1;
        
        while(low <= high) {
            int mid = low + (high-low)/2;
            int prev = mid - 1;
            int next = mid + 1;
            if(0 < mid && mid < n-1){
                if(nums[prev] < nums[mid] && nums[mid] > nums[next]) {
                    return mid;
                } else if(nums[prev] > nums[mid]) {
                    high = mid-1;
                } else {
                    low = mid+1;
                }
            } else if(mid == 0) {
                if(nums[mid] > nums[next])return mid;
                else return next;
            } else if(mid == n-1) {
                if(nums[mid] > nums[prev])return mid;
                else return prev;
            }
        }
        
        return -1;
    }
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1)return 0;
        int idx = search(nums);
        
        return idx;
    }
};