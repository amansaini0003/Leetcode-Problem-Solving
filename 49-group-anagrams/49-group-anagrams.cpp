class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<string>> mp;
        
        for(int i=0; i<strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            string key = s;
            if(mp.find(key) != mp.end()){
                mp[key].push_back(strs[i]);
            } else {
                vector<string> v;
                v.push_back(strs[i]);
                mp[key] = v;
            }
        }
        
        for(auto i: mp) {
            ans.push_back(i.second);
        }
        return ans;
    }
};