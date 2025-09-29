class Solution {
public:
    bool isPos(char ch ,int row , int col , vector<vector<char>>& board){
        // once in that row
        for(int i = 0 ; i < 9 ; i++){
            if(board[row][i] == ch) return false;
        }

        // once in that col
        for(int i = 0 ; i < 9 ; i++){
            if(board[i][col] == ch) return false;
        }

        // once in that 3x3 sub-box

        int row_start = (row/3) * 3;
        int col_start = (col/3) * 3;

        for(int i = row_start ; i < row_start + 3 ; i++){
            for(int j = col_start ; j < col_start + 3 ; j++){
                if(board[i][j] == ch){
                    return false;
                }
            }
        }

        return true;
    }

    bool boardFill(vector<vector<char>>& board){
        for(int row = 0 ; row < 9 ; row++){
            for(int col = 0 ; col < 9 ; col++){
                if(board[row][col] == '.'){
                    for(int i = '1' ; i <= '9' ; i++){
                        if(isPos(i ,row , col ,  board)){
                            board[row][col] = i;
                            if(boardFill(board)) return true;
                            board[row][col] = '.';
                        }
                    }

                    return false;
                }
            }
        } 

        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        boardFill(board);
    }
};