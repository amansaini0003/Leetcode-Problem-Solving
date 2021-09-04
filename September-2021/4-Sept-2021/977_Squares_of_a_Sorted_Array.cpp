class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> v;
        int pos = nums.size(), flag = 1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<0){
                v.push_back(nums[i]*nums[i]);
                continue;
            }
            if(flag){
                pos = i;
                flag=0;
            }
            
            nums[i] = nums[i]*nums[i];
        }
            
        int j=v.size()-1, k=0, i=pos;
        
        while(i<nums.size() && j>=0){
            if(nums[i]<=v[j])
                nums[k++] = nums[i++];
            else
                nums[k++] = v[j--];
        }
        while(j>=0)
            nums[k++] = v[j--];
        
        while(i<nums.size())
            nums[k++] = nums[i++];
        
        return nums;
    }
};