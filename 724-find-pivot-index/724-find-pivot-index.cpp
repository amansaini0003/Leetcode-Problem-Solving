class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n, 0);
        int pivotIndex = -1;
        
        arr[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--) {
            arr[i] = arr[i+1] + nums[i];
        }
        int sum = 0;
        for(int i = 0; i<n; i++) {
            sum += nums[i];
            if(sum == arr[i])
                return i;
        }
        
        return pivotIndex;
    }
};
