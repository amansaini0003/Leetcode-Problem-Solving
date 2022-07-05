class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto i: nums){
            s.insert(i);
        }
        
        int maxStreak = 0;
        
        for(auto i: nums){
            if( !(s.find(i-1) != s.end()) ){
                int currStreak = 1;
                int currNum = i;
                while(s.find(currNum+1) != s.end()){
                    currNum++;
                    currStreak++;
                }
                maxStreak = max(currStreak, maxStreak);
            }
        }
        
        return maxStreak;
    }
};