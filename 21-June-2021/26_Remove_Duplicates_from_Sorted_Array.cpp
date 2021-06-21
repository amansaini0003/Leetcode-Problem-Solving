/* Problem Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

Approach 1: T.C = O(n)  erase fun. can take O(n^2) in worst case;
            S.C = O(1)
Approach 2: Two Pointer Approach (Optimal)
            T.C = O()
            S.C = O(1)
*/

//                   Approach 1: 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)return 0;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]==nums[i+1]){
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        return nums.size();
    }
};

//                   Approach 2

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int i=0;
        for(int j=1; j<nums.size(); j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};
