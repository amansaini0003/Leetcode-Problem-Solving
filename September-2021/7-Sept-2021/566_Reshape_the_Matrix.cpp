// Approach 1: Naive
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row = mat.size(), col = mat[0].size();
        
        if(row*col != r*c)
            return mat;
        
        vector<vector<int>> grid(r, vector<int> (c,0));
        vector<int> oneD (r*c, 0);
        
        int k=0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                oneD[k]= mat[i][j];
                k++;
            }
        }
        k=0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                grid[i][j] = oneD[k];
                k++;
            }
        }
        return grid;
    }
};

// Approach 2: Optimal

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row = mat.size(), col = mat[0].size();
        
        if(row*col != r*c)
            return mat;
        
        int n = r*c;
        vector<vector<int>> grid(r, vector<int> (c,0));
        
        for(int i=0; i<n; i++){
            grid[i/c][i%c] = mat[i/col][i%col];
        }
        
        return grid;
    }
};