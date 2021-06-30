/* Problem Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/


/*Approach 2: Using 2 pointer and Hashing
            T.C = O(N)
            S.C = O(1) === max 256 char's
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int currWindowSize = 0, maxWindowSize = 0;
        map<char, int> mp;
        
        for(int j=0; j<s.size(); j++){
            if(mp.find(s[j])==mp.end())
                mp[s[j]] = j;
            else{
                
                if(mp[s[j]] >= i)
                    i = mp[s[j]] + 1;
                mp[s[j]] = j ;
            }
            
            currWindowSize = j-i+1;
            maxWindowSize = max(maxWindowSize, currWindowSize);
        }
        
        return maxWindowSize;
    }
};




/*Approach 1: Using 2 pointer and Hashing
            T.C = O(2N)
            S.C = O(1) === max 256 char's
*/
class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int currWindowSize = 0, maxWindowSize = 0;
        unordered_set<char> st;
        
        for(int j=0; j<s.size(); j++){
            if(st.find(s[j])==st.end())
                st.insert(s[j]);
            else{
                while(st.find(s[j])!=st.end() ){
                    st.erase(s[i]);
                    i++;
                }
                
                st.insert(s[j]);
            }
            
            currWindowSize = j-i+1;
            maxWindowSize = max(maxWindowSize, currWindowSize);
        }
        
        return maxWindowSize;
    }
};
