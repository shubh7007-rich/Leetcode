class Solution {
public:
    bool isSafe(int row , int col , vector<string>& board , int n){
        int r1 = row - 1;
        int c1 = col - 1;

        while(r1 >= 0 && c1 >= 0){
            if(board[r1][c1] == 'Q') return false;
            r1--;
            c1--;
        }
        c1 = col - 1 , r1 = row+1;
        while(r1 < n && c1 >= 0){
            if(board[r1][c1] == 'Q') return false;
            r1++;
            c1--;
        }

        r1 = row , c1 = col-1;
        while(c1 >= 0){
            if(board[r1][c1] == 'Q') return false;
            c1--;
        }

        return true;
    }
    void func(int col , vector<string>& board , int n , vector<vector<string>>& ans){
        if(col >= n){
            ans.push_back(board);
            return;
        }

        for(int row = 0 ; row < n ; row++){
            if(isSafe(row , col , board , n)){
                board[row][col] = 'Q';
                func(col+1 , board , n , ans);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        string str(n , '.');

        vector<vector<string>> ans;

        for(int i = 0 ; i < n ; i++){
            board.push_back(str);
        }

        for(int row = 0 ; row < n ; row++){
            board[row][0] = 'Q';
            func(1 , board , n , ans);
            board[row][0] = '.';
        }

        return ans;
    }
};