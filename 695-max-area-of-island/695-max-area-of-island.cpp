class Solution {
private:
    void bfs(int i, int j, int &area, vector<vector<bool>> &vis, vector<vector<int>> &grid) {
        int row = grid.size(), col = grid[0].size();
        
        if(i < 0 || j < 0 || i >= row || j >= col) 
            return;
        
        if(vis[i][j] || grid[i][j] == 0)
            return;
        
        vis[i][j] = 1;
        area++;
        
        bfs(i+1, j, area, vis, grid);
        bfs(i-1, j, area, vis, grid);
        bfs(i, j+1, area, vis, grid);
        bfs(i, j-1, area, vis, grid);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(grid[i][j] == 1 && !vis[i][j]){
                    int area = 0;
                    bfs(i, j, area, vis, grid);
                    maxArea = max(area, maxArea);
                }
            }
        }
        
        return maxArea;
    }
};