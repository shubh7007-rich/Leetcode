class Solution {
public:
    int dp[201][201];

    int inf = 1e7; 
    int func(int r , int c , vector<vector<int>>& tri , int n){
        if(r == n-1){
            return tri[r][c];
        }
        if(dp[r][c] != inf) return dp[r][c];
        int go = tri[r][c] + func(r+1 , c , tri , n);
        int go1 = tri[r][c] + func(r+1 , c+1 , tri , n);

        return dp[r][c] = min(go , go1);
    }
    int minimumTotal(vector<vector<int>>& tri) {
        // memset(dp , -1 , sizeof(dp));
        for(int i = 0 ; i < 201 ; i++)
            for(int j = 0 ; j < 201 ; j++)
                dp[i][j] = inf;

        return func(0 , 0 , tri , tri.size());
    }
};