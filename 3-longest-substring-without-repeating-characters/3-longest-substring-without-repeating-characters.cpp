class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, maxLen = 0;
        unordered_map<char, int> mp;
        
        for(int end = 0; end < s.size(); end++){
            char ch= s[end];
            
            if(mp.find(ch) != mp.end()){
                if(mp[ch] >= start){
                    start = mp[ch]+1;
                }
            }
            int len = end - start + 1;
            maxLen = max(len, maxLen);
            mp[ch] = end;
        }
        
        return maxLen;
    }
};