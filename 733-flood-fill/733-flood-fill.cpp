class Solution {
private: 
    void bfs(int i, int j, int orgColor, int color, vector<vector<int>>& image) {
        int rows = image.size(), cols = image[0].size();
        if(i < 0 || j < 0 || i >= rows || j >= cols)
            return;
        if(image[i][j] == color || image[i][j] != orgColor)
            return;
        
        image[i][j] = color;
        
        bfs(i+1, j, orgColor, color, image);
        bfs(i-1, j, orgColor, color, image);
        bfs(i, j+1, orgColor, color, image);
        bfs(i, j-1, orgColor, color, image);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orgColor = image[sr][sc];
        bfs(sr, sc, orgColor, color, image);
        return image;
    }
};