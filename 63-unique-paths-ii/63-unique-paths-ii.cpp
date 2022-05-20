class Solution {
private: 
    int traverse(int i, int j, vector<vector<int>> &t ,vector<vector<int>> &obstacleGrid) {
       
        cout << i << " " << j << endl; 
        if(i>= 0 && j>=0 && obstacleGrid[i][j] == 1)
            return 0;
        
        if(i == 0 && j == 0){
            return 1;
        }
        
        if(i < 0 || j < 0){
            return 0;
        }
            
        if(t[i][j] != -1)
            return t[i][j];
    
        int left = traverse(i, j-1, t, obstacleGrid);
        int up = traverse(i-1, j, t, obstacleGrid);

        return t[i][j] = left+up;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int i = 0, j = 0;
        int row = obstacleGrid.size() , col = obstacleGrid[0].size();
        vector<vector<int>> t(row+1, vector<int> (col+1, -1));
        
        if(obstacleGrid[row-1][col-1] == 1 || obstacleGrid[0][0] == 1){
            return 0;
        }
        
        return traverse(row-1, col-1, t, obstacleGrid);
        
    }
};