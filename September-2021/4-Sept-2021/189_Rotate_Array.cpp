class Solution {
public:
    
    void solve(int left, int right, vector<int> &nums){
        while(left<right)
            swap(nums[left++], nums[right--]);
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>=n)
            k=k%n;
        solve(0, n-1, nums);
        solve(0, k-1, nums);   
        solve(k, n-1, nums);
    }
};