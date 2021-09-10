class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        
        int n = shifts.size();
        
        int sum = 0;
        
        for(int i=n-1; i>=0; i--){
            sum += shifts[i];
            
            int shiftby = sum%26;
            if(s[i] - 'a' + shiftby >= 26){
                shiftby -= 'z'- s[i]+1;
                s[i]='a';
            }

            s[i] += shiftby;
            sum %= 26;
        }
        return s;
    }
};