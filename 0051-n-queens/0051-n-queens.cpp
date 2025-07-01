class Solution {
public:
    bool isSafe(int r , int c , vector<string>& board , int n){
        
        int r1 = r , c1 = c;

        while(r1 >= 0){
            if(board[r1][c1] == 'Q') return false;
            r1--;
        }
        r1 = r;

        while(r1 >= 0 && c1 >= 0){
            if(board[r1][c1] == 'Q') return false;
            r1--;
            c1--;
        }

        r1 = r;
        c1 = c;

         while(r1 >= 0 && c1 < n){
            if(board[r1][c1] == 'Q') return false;
            r1--;
            c1++;
        }
        return true;
    }
    void func(int ind , vector<string>& board , vector<vector<string>> & ans , int n){

        if(ind == n){
            ans.push_back(board);
            return;
        }

        for(int i = 0 ; i < n ; i++){
            if(isSafe(ind , i , board , n)){
                board[ind][i] = 'Q';
                func(ind+1 , board , ans , n);
                board[ind][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        vector<string> board;

        string str(n , '.');

        for(int i = 0 ; i < n ; i++){
            board.push_back(str);
        }

        for(int i = 0 ; i < n ; i++){
            board[0][i] = 'Q';
            func(1 , board , ans , n);
            board[0][i] = '.';
        }


        return ans;
    }
};