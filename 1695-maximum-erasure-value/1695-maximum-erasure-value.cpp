class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maxScore = 0, start = 0;
        int n = nums.size();
        vector<int> pre(n);
        unordered_map<int, int> mp;
        
        pre[0] = nums[0];
        for(int i=1; i<nums.size(); i++) {
            pre[i] = pre[i-1] + nums[i];
        }
        
        for(int end = 0; end < n; end++) {
            int num = nums[end];
            
            
            if(mp.find(num) != mp.end()) {
                int lastOccurAt = mp[num];
                if(lastOccurAt >= start){
                    start = lastOccurAt + 1;
                }
            }
            mp[num] = end;
            int score = pre[end] - pre[start] + nums[start];
            maxScore = max(score, maxScore);
        }
        
       return maxScore;
    }
};