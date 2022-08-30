class Solution {
private: 
    void reverse(vector<vector<int>> &arr) {
        int n = arr.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n/2; j++){
                swap(arr[i][j], arr[i][n-j-1]);
            }
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        reverse(matrix);
    }
};