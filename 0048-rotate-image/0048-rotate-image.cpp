class Solution {
private: 
    void rotateArray(vector<int> &arr) {
        int low = 0, high = arr.size()-1;
        
        while(low < high) {
            swap(arr[low], arr[high]);
            low++;
            high--;
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        
        for(int i=0; i<rows; i++) {
            for(int j=0; j<i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<rows; i++) {
            rotateArray(matrix[i]);
        }
    }
};