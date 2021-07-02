/* Problem Link : https://leetcode.com/problems/find-the-duplicate-number/
    
    Approach 1 : Using 2 loop
                T.C = O(N^2)
                S.C = O(1)

    Approach 2 : Sorting
                T.C = O(NlogN) + O(N)
                S.C = O(1)

    Approach 3 : Using Hashing
                T.C = O(N)
                S.C = O(N)
    
    Approach 4 : Cycle Detection
                T.C = O(N)
                S.C = O(1)
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        fast = nums[0];
        
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};