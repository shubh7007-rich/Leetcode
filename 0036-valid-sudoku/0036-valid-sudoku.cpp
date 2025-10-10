class Solution {
public:
    bool isValid(int r , int c , char val , vector<vector<char>>& board){
        int cnt = 0;
        for(int i = 0 ; i < 9 ; i++){
            if(board[r][i] == val){
                cnt++;
            }

            if(cnt > 1) return false;
        }
        cnt = 0;
        for(int i = 0 ; i < 9 ; i++){
            if(board[i][c] == val){
                cnt++;
            }

            if(cnt > 1) return false;
        }

        int rStart = (r/3) * 3 , cStart = (c/3) * 3;
        cnt = 0;

        for(int i = rStart ; i < rStart + 3 ; i++){
            for(int j = cStart ; j < cStart + 3 ; j++){
                if(board[i][j] == val){
                    cnt++;
                }
                if(cnt > 1) return false;
            }
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                if(board[i][j] != '.'){
                    char val = board[i][j];

                    if(!isValid(i , j , val , board)) return false;
                }
            }
        }

        return true;
    }
};