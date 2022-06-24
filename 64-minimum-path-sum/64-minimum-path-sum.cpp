class Solution {
private: 
    int t[201][201];
    int minPathSumUtil(int i, int j, vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        
        if(i>=n || j >= m)
            return INT_MAX;
        if(i == n-1 && j == m-1)
            return grid[i][j];
        
        
        if(t[i][j] != -1)
            return t[i][j];
        
         t[i][j] = grid[i][j] + min(minPathSumUtil(i+1, j, grid), minPathSumUtil(i, j+1, grid));
        
        return t[i][j];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        memset(t, -1, sizeof(t));
        return minPathSumUtil(0, 0, grid);
    }
};