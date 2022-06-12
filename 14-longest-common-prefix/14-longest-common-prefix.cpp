class Solution {
private: 
    string getCommonPrefix(string s1, string s2) {
        int i = 0, j = 0;
        
        string pre = "";
        
        while(i<s1.size() && j<s2.size()){
            if(s1[i] == s2[j])
                pre += s1[i];
            else 
                break;
            i++,j++;
        }
        
        return pre;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        string op = strs[0];
        
        for(int i=1; i<strs.size(); i++) {
            string str = strs[i];
            
            op = getCommonPrefix(str, op);
            if(op == "")
                break;
        }
        
        return op;
    }
};