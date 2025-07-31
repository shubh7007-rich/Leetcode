// #define ll long long
class Solution {
public:
    vector<vector<int>> directions = {{1,0} , {0,1}};
    int dp[200][200];
    int inf = 1e9;

    int func(int r , int c ,int n , int m , vector<vector<int>>& grid){
        if(r == n-1 && c == m-1){
            return grid[r][c];
        }
        int cost = inf;

        if(dp[r][c] != -1) return dp[r][c];

        for(vector<int>& vec : directions){
            int r1 = r + vec[0] , c1 = c + vec[1];

            if(r1 >= 0 && r1 < n && c1 >= 0 && c1 < m && grid[r1][c1] >= 0){
                int temp = grid[r][c];
                grid[r][c] = -1;
                cost = min(cost , temp + func(r1 , c1 , n , m  , grid));
                grid[r][c] = temp;
            }
        }

        return dp[r][c] = cost;
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp , -1 , sizeof(dp));
        int n = grid.size() , m = grid[0].size();
        return func(0 ,0 , n , m , grid);
    }
};