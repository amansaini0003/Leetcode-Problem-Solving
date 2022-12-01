class Solution {
public:
    bool halvesAreAlike(string s) {
        int len = s.size();
        int count = 0;        
        for(int i=0; i<len/2; i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                count++;        
            }
        }
        
        for(int i= len/2; i<len; i++) {
           if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                count--;        
            }
        }
        
        return count != 0 ? false : true;
    }
};