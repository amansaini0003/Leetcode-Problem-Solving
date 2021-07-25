// Problem Link: https://leetcode.com/problems/find-the-town-judge/

// Approach: https://leetcode.com/problems/find-the-town-judge/discuss/1359412/c-easy-solution-tc-osizeoftrust-sc-on-beats-875-c-solution

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int indeg[n+1], outdeg[n+1];
        
        memset(indeg, 0, sizeof(indeg));
        memset(outdeg, 0, sizeof(outdeg));
        
        int size = trust.size();
        
        for(int i=0; i<size; i++){
            int u = trust[i][0], v= trust[i][1];
            
            outdeg[u]++;
            indeg[v]++;
        }
        
        for(int i=1 ; i<=n; i++){
            if(indeg[i]==n-1 && outdeg[i]==0)
                return i;
        }
        return -1;
    }
};