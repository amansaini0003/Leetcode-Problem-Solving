class NumMatrix {
private: 
    int pre[202][202];
public:
    NumMatrix(vector<vector<int>>& matrix) {
        memset(pre, 0, sizeof(pre));
        
        int row = matrix.size(), col = matrix[0].size();
        
        for(int i=1; i<=row; i++) {
            for(int j=1; j<=col; j++) {
                pre[i][j] = matrix[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int a, int b, int c, int d) {
        a++,b++,c++,d++;
        int sum = pre[c][d] - pre[a-1][d] - pre[c][b-1] + pre[a-1][b-1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */