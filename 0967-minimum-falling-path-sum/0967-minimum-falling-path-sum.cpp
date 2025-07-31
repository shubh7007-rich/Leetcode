class Solution {
public:
    int inf = 1e9 , inf2 = 1e5;

    vector<vector<int>> directions = {{1,-1} , {1,0} , {1,1}};

    int dp[100][100];

    int func(int r , int c , vector<vector<int>>& matrix , int n){
        if(r == n-1){
            return matrix[r][c];
        }   

        int cost = inf;

        if(dp[r][c] != inf2) return dp[r][c];

        for(vector<int> & vec : directions){
            int r1 = r + vec[0] , c1 = c + vec[1];

            if(r1 >= 0 && r1 < n && c1 >= 0 && c1 < n){
                cost = min(cost , matrix[r][c] + func(r1 , c1 , matrix , n));
            }
        }

        return dp[r][c] = cost;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int cost = inf , n = matrix.size();
        for (int i = 0; i < 100; i++)
            for (int j = 0; j < 100; j++)
                dp[i][j] = inf2;

        for(int i = 0 ; i < n ; i++){
            cost = min(cost , func(0 , i , matrix , n));
        }

        return cost;
    }
};