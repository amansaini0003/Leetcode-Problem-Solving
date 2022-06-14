class Solution {
private: 
    int t[501][501];
    int lcs(int n, int m, string &word1, string &word2){
        if(n == 0 || m == 0)
            return 0;
        
        if(t[n][m] != -1)
            return t[n][m];
        
        if(word1[n-1] == word2[m-1]){
            return t[n][m] = 1 + lcs(n-1, m-1, word1, word2);
        }
        
        return t[n][m] = max(lcs(n-1, m, word1, word2), lcs(n, m-1, word1, word2));
    }
public:
    int minDistance(string word1, string word2) {
        memset(t, -1, sizeof(t));
        
        int n = word1.size(), m = word2.size();
        
        int l = lcs(n, m, word1, word2);
        
        int res = (n-l) + (m-l);
        return res;
    }
};