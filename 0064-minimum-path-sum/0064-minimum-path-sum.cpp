class Solution {
public:
    int dp[201][201];
    int func(int r , int c , int n , int m , vector<vector<int>>& obs){
        if(r >= n || c >= m) return 1e8;

        if(r == n-1 && c == m-1) return obs[r][c];

        if(dp[r][c] != -1) return dp[r][c];

        int down = obs[r][c] + func(r+1 , c , n , m , obs);

        int right = obs[r][c] + func(r , c+1, n , m , obs);

        return dp[r][c] = min(down , right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        memset(dp , -1 , sizeof(dp));
        return func(0 , 0 , n , m , grid);
    }
};