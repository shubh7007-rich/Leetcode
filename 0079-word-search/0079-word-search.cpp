class Solution {
public:
    vector<vector<int>> directions = {{1 , 0} , {-1, 0} , {0,1} , {0,-1}};

    bool isSafe(int r , int c , int n , int m){
        return (r >= 0 && r < n && c >= 0 && c < m);
    }

    bool func(int r , int c, int ind , vector<vector<char>>& board, string& word ,int n , int m , vector<vector<int>>& vis){
        if(r < 0 || r >= n || c < 0 || c >= m) return false;

        if(ind == word.length()) return true;

        for(vector<int> & dir : directions){
            int r1 = r + dir[0], c1 = c + dir[1];

            if(isSafe(r1 , c1 , n , m) && (board[r1][c1] == word[ind]) && !vis[r1][c1]){
                vis[r1][c1] = 1;
                if(func(r1 , c1 , ind+1 , board , word , n , m , vis)){
                    return true;
                }
                vis[r1][c1] = 0;
            }
        }

        return false;
    }

    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size() , m = board[0].size();
        string temp = "";

        vector<vector<int>> vis(n , vector<int>(m , 0));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == word[0]){
                    temp += word[0];
                    vis[i][j] = 1;
                    if(func(i , j , 1 , board , word , n , m , vis)){
                        return true;
                    }
                    vis[i][j] = 0;
                    temp.pop_back();
                }
            }
        }

        return false;
    }
};