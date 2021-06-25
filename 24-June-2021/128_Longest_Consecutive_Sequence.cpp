/* Problem Link : https://leetcode.com/problems/longest-consecutive-sequence/

Approach 1: Using Sorting 
            T.C = O(NlogN)
            S.C = O(1)
Approach 1: Using Unordered Set
            T.C = O(N) 
            S.C = O(N) for set
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int maxStreak = 0;
        for(auto i : nums)
            s.insert(i);
        
        for(auto i: nums){
            if(s.find(i-1)==s.end()){   
                int currNum = i;
                int currStreak = 1;
            
                while(s.find(currNum+1)!=s.end()){
                    currNum += 1;
                    currStreak += 1; 
                }
                 maxStreak = max(maxStreak, currStreak);
            }
        }
        
        return maxStreak;
    }
};