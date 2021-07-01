/* Problem Link : https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

    Approach 1 : LinerSearch
                T.C = O(m*n)
                S.C = O(1)
    Approach 2 : Binary search on each array in grid : 
                T.C = O(m * logn)
                S.C = O(1)
    Approach 3 : Binary search on grid : 
                T.C = O(m + n)
                S.C = O(1)
*/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int i = 0, j = n-1, count = 0;
        
        while(i<=m-1 && j>=0){
            if(grid[i][j] < 0)
                j--;
            else{
                count += n-j-1;
                i++;
            }
        }
        
        if(j==-1){
            count += n;
            count += n * (m-i-1);
        }
        return count;
    }
};