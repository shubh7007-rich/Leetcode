class Solution {
public:
    // int dp[25][25][101];
    // map<tuple<int , int , int> , double> dp;
    unordered_map<string , double> dp;
    vector<vector<int>> directions = {{-2,-1} , {-2,1} , {-1,-2} , {1,-2} , {2,-1} , {2,1} , {-1,2} , {1,2}};
    double func(int r , int c , int n , int k){
        if(r < 0 || r >= n || c < 0 || c >= n) return 0;

        if(k == 0) return 1;

        double prob = 0;

        // tuple<int , int , int> key = {r , c , k};
        string key = to_string(r) + "," + to_string(c) + "," + to_string(k) ;

        // if(dp[r][c][k] != -1) return dp[r][c][k];
        if(dp.count(key)) return dp[key];

        for(vector<int>& dir : directions){
            prob += func(r + dir[0] , c + dir[1] , n , k-1);
        }


        return dp[key] = prob/8;
    }
    double knightProbability(int n, int k, int row, int column) {
        // memset(dp , -1 , sizeof(dp));
        
        return func(row , column , n , k);
    }
};