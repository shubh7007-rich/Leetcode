class Solution {
public:
    int dp[300][300];
    int maxi = 0;
    int func(int i , int j , vector<vector<char>>& matrix, int n , int m){
        if(i >= n || j >= m) return 0;

        if(matrix[i][j] == '0') return 0;

        if(dp[i][j] != -1) return dp[i][j]; 

        int right = func(i , j+1 , matrix , n , m);
        int diagonal = func(i+1 , j+1 , matrix , n , m);
        int down = func(i+1 , j , matrix , n , m);
        maxi = max(maxi , 1 + min({right , diagonal , down}));
        return dp[i][j] = 1 + min({right , diagonal , down});
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int cnt = 0 , n = matrix.size() , m = matrix[0].size();
        memset(dp , -1 , sizeof(dp));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] == '1'){
                    func(i , j , matrix , n , m);
                }
            }
        }

        return maxi*maxi;
    }
};