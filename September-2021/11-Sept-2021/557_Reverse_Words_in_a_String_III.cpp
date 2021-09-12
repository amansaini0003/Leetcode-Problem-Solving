class Solution {
public:
    
    string reverseWords(string s) {
        string rev = "", substr = "";
        s+=' ';
        
        for(int i=0; i<s.size(); i++){
            if(s[i]==' '){
                reverse(substr.begin(), substr.end());
                rev += substr;
                rev += ' ';
                substr = "";
            }
            else
                substr += s[i];
        }
        // Remove space from last;
        rev.pop_back();
        return rev;
    }
};