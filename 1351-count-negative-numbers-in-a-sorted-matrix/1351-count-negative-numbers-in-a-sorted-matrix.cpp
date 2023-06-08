class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int x = cols - 1, y = 0;
        int total_negative_numbers = 0;
        while(x >= 0 && y < rows) {
            if(grid[y][x] < 0) {
                total_negative_numbers += rows - y;
                x--;
            } else {
                y++;
            }
        }
        
        return total_negative_numbers;
    }
};