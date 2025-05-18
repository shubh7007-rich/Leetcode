class Solution {
public:
    int dp[101][101];
    int func(int r , int c , int n , int m , vector<vector<int>>& obs){
        if(r == n-1 && c == m-1) return 1;

        if(r >= n || c >= m) return 0;

        if(obs[r][c] == 1) return 0;

        if(dp[r][c] != -1) return dp[r][c];

        int down = func(r+1 , c , n , m , obs);

        int right = func(r , c+1, n , m , obs);

        return dp[r][c] = down + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int n = obs.size() , m = obs[0].size();

        if(obs[0][0] == 1 || obs[n-1][m-1] == 1) return 0;

        memset(dp , -1 , sizeof(dp));

        return func(0 , 0 , n , m , obs);
    }
};