class Solution {
private:
    queue<pair<int, int>> q;
    int minutes = 0;
    
    vector<int> dirx = {0, 0, 1, -1};
    vector<int> diry = {1, -1, 0, 0};
    
    bool isValidIdx(int i, int j, int rows, int cols){
        if(i<0 || i>=rows || j<0 || j>=cols){
            return false;
        }
        return true;
    }
    
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis) {
        int m = grid.size(), n = grid[0].size();
        while(!q.empty()) {
            minutes++;
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                pair<int, int> p = q.front();
                q.pop();
                int x = p.first, y = p.second;
                    
                for(int dir = 0; dir<4; dir++){
                    int dx = x + dirx[dir];
                    int dy = y+ diry[dir];
                    if(isValidIdx(dx, dy, m, n) && grid[dx][dy] == 1 && !vis[dx][dy]){
                        q.push({dx, dy});
                        grid[dx][dy] = 2;
                        vis[dx][dy] = 1;
                    }
                }
            }
        }
    }
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        
        bool isFreshApplePresent = false;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                if(grid[i][j] == 1){
                    isFreshApplePresent = true;
                }
            }
        }
        
        if(!isFreshApplePresent) {
            return 0;
        }
        
        dfs(grid, vis);
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return minutes > 0 ? minutes-1: minutes;
    }
};