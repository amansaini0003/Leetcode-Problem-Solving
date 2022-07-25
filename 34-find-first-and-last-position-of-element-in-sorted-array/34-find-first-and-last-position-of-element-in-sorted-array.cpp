class Solution {
private:
    int getFirstPos(vector<int> &nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low < high) {
            int mid = low+(high-low)/2;
            if(nums[mid] < target){
                low = mid+1;
            } else {
                high = mid;
            }
        }
        return nums[high] == target ? high : -1;
    }
   
    int getLastPos(vector<int> &nums, int target) {
        int low = 0, high = nums.size()-1;
        int ub = 0;
        
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(target < nums[mid]){
                high = mid-1;
            } else {
                ub = mid;
                low = mid+1;
            }
        }
        
        return nums[ub] == target ? ub : -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        if(nums.size() == 0){
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }
            
        int startPos = getFirstPos(nums, target);
        int endPos = getLastPos(nums, target);
        v.push_back(startPos);
        v.push_back(endPos);
        
        return v;
    }
};