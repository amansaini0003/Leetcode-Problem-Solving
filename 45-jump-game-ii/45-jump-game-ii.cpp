class Solution {
private: 
    int t[10001];
    int minSteps(int i, vector<int> &nums) {
        int n = nums.size();
        if(i >= n-1){
            return 0;
        }

        if(t[i] != 10006)
            return t[i];
        
        for(int j=1; j<=nums[i]; j++) {
            t[i] = min(t[i], 1 + minSteps(i+j, nums));
        }
        
        return t[i];
    }

public:
    int jump(vector<int>& nums) {
        for(int &i: t) {
            i = 10006;
        }
        int res = minSteps(0, nums);
        return res;
    }
};