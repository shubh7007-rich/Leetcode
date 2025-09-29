class Solution {
public:
    bool isSafe(int row , int col , vector<string>& board , int n){
        int r = row , c = col;

        while(c >= 0){
            if(board[r][c] == 'Q') return false;
            c--;
        }

        c = col;

        while(r >= 0 && c >= 0){
            if(board[r][c] == 'Q') return false;
            c--;r--;
        }
        r = row;
        c = col;
        while(r < n && c >= 0){
            if(board[r][c] == 'Q') return false;
            c--;r++;
        }

        return true;


    }
    void func(int col , vector<string>& board , vector<vector<string>>& ans , int n){
        if(col >= n){
            ans.push_back(board);
            return;
        }

        for(int row = 0 ; row < n ; row++){
            if(isSafe(row , col , board , n)){
                board[row][col] = 'Q';
                func(col+1 , board , ans , n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string str(n , '.');
        vector<string> board;
        vector<vector<string>> ans;
        for(int i = 0 ; i < n ; i++){
            board.push_back(str);
        }

        for(int row = 0 ; row < n ; row++){
            board[row][0] = 'Q';
            func(1 , board , ans , n);
            board[row][0] = '.';
        }

        return ans; 
    }
};