// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    private: 
    vector<string> allPaths;
    void solve(int row, int col, string path,vector<vector<int>> &mat){
        int n = mat.size();
        if(row < 0 || row >= n || col < 0 || col >= n || mat[row][col] == 0){
            return;
        }
        if(row == n-1 && col == n-1){
            allPaths.push_back(path);
            return;
        }
        for(int dir = 1; dir <= 4; dir++){
            mat[row][col] = 0;
            if(dir == 1){           // right
                path.push_back('R');
                solve(row, col+1, path, mat);
            } else if(dir == 2) {   // down
                path.push_back('D');
                solve(row+1, col, path, mat);
            } else if(dir == 3) {   // left
                path.push_back('L');
                solve(row, col-1, path, mat);
            } else {                // up
                path.push_back('U');
                solve(row-1, col, path, mat);
            }
            mat[row][col] = 1;
            path.pop_back();
        }
        
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &mat, int n) {
        if(mat[0][0] == 0 || mat[n-1][n-1] == 0)
            return allPaths;
        
        string path = "";
        
        solve(0, 0, path, mat);
        
        return allPaths;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends