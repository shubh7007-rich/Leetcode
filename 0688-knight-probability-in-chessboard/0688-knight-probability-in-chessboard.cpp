class Solution {
public:
    double dp[25][25][101];

    vector<vector<int>> directions = {{-2,-1} , {-2,1} , {-1,-2} , {1,-2} , {2,-1} , {2,1} , {-1,2} , {1,2}};
    
    double func(int i , int j , int n , int k){
        if(i < 0 || i >= n || j < 0 || j >= n) return 0;
        if(k == 0) return 1;

        if(dp[i][j][k] >= 0.0) return dp[i][j][k];

        double prob = 0;
        for(auto& d : directions){
            int ni = i + d[0];
            int nj = j + d[1];
            prob += func(ni, nj, n, k-1);
        }

        return dp[i][j][k] = prob / 8.0;
    }

    double knightProbability(int n, int k, int row, int column) {
        memset(dp , -1 , sizeof(dp));
        return func(row , column , n , k);
    }
};
