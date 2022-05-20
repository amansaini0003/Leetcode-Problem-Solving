class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int i = 0, j = 0;
        int row = obstacleGrid.size() , col = obstacleGrid[0].size();
        vector<vector<int>> t(row, vector<int> (col));
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                 if(obstacleGrid[i][j] == 1){
                    t[i][j] = 0;
                }
                else if(i==0 && j==0){
                    t[i][j] = 1;
                }
                else {
                    int up = 0, left = 0;
                    
                    if(i>0){ 
                        up = t[i-1][j]; 
                    }
                    if(j>0){ 
                        left = t[i][j-1]; 
                    }
                    
                    t[i][j] = up + left;
                }
            }
        }
        
        return t[row-1][col-1];
    }
};