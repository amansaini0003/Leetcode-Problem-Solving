class Solution {
public:
    
    bool isValidBox(int r, int c, vector<vector<char>>& board){
        int count[10] = {0};
        for(int i=r; i<r+3; i++){
            for(int j=c; j<c+3; j++){
                if(board[i][j]=='.')
                    continue;
                count[board[i][j]-'0']++;
                if(count[board[i][j]-'0'] > 1)
                    return false;
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        bool check = true;
        int count[10] = {0};
        
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.')
                    continue;

                count[board[i][j]-'0']++;
                if(count[board[i][j]-'0'] > 1)
                     return false;
            }
            memset(count, 0, sizeof(count));
        }
        
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[j][i]=='.')
                    continue;
                count[board[j][i]-'0']++;
                if(count[board[j][i]-'0'] > 1)
                    return false;
            }
            memset(count, 0, sizeof(count));
        }
        
        for(int i=0; i<9; i+=3){
            for(int j=0; j<9; j+=3){
                if(!isValidBox(i, j, board))
                    return false;
            }
        }
        
        return true;
    }
};