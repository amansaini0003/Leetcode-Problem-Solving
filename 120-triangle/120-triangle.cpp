class Solution {
private:
    int dp[201][201];
public:
    int getMin(int i, int j, vector<vector<int>>& triangle) {
        int rows = triangle.size(), cols = triangle[i].size();
        
        if(i == rows-1){
            return triangle[i][j];
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ls = triangle[i][j] + getMin(i+1, j, triangle);
        int rs = triangle[i][j] + getMin(i+1, j+1, triangle);
        
        dp[i][j] = min(ls, rs);
        return dp[i][j];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp, -1, sizeof(dp));
        int i=0, j=0;
        int res = getMin(i, j, triangle);
        
        return res;
    }
};