class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int cnt = 0;
        int prevDiff = 0;
        
        if(nums.size() == 1)return 1;
        if(nums.size() == 2){
            if(nums[1]-nums[0] == 0)
                return 1;
            return 2;
        }
        
        for(int i=1; i<nums.size(); i++) {
            int currDiff = nums[i] - nums[i-1];
            if(i == 1) {
                if(nums[1]-nums[0] != 0)
                    cnt = 2;
                else
                    cnt = 1;
                prevDiff = currDiff;
                continue;
            }
           
            if(currDiff > 0 && prevDiff <=0  ) {
                cnt++;
                 prevDiff = currDiff;
            } else if(currDiff < 0 && prevDiff >= 0){
                cnt++;
                 prevDiff = currDiff;
            } 
        }
        
        return cnt;
    }
};