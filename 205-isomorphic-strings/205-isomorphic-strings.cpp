class Solution {
private:
    bool solve(string s, string t){
        map<char, char> mp;
        for(int i=0; i<t.size(); i++) {
            if(mp.find(t[i]) != mp.end() && mp[t[i]] != s[i])
                return false;
            mp[t[i]] = s[i];
        }
        return true;
    }
public:
    bool isIsomorphic(string s, string t) {
        return solve(s, t) && solve(t, s);
    }
};