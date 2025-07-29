class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        boardFill(board);
    }

    bool boardFill(vector<vector<char>>& board){
        for(int row = 0 ; row < 9 ; row++){
            for(int col = 0 ; col < 9 ; col++){
                if(board[row][col] == '.'){

                    for(char c = '1' ; c <= '9' ; c++){
                        if(isPossible(c , row , col , board)){
                            board[row][col] = c;
                            if(boardFill(board)){
                                return true;
                            }
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }

    bool isPossible(char c , int row , int col , vector<vector<char>>& board){

        for(int i = 0 ; i < 9 ; i++){
            if(board[row][i] == c) return false;   // row check
            if(board[i][col] == c) return false;  // col check
        }

        // now checking for the 3 x 3 grid

        int rNo = (row/3) * 3 , cNo = (col/3) * 3;

        for(int i = rNo ; i < rNo + 3 ; i++){
            for(int j = cNo ; j < cNo + 3 ; j++){
                if(board[i][j] == c) return false;
            }
        }

        return true;
    }
};