class Solution {
public:
    int inf = 1e5;
    int dp[10001];
    int solve(int sum , int n){
        if(sum > n) return inf;

        if(sum == n) return 0;
        if(dp[sum] != -1) return dp[sum];

        int count = 0 , minCount = INT_MAX;
        for(int i = 1; i*i <= (n-sum) ; i++){
            int count = 1 + solve(sum + (i*i) , n);

            minCount = min(minCount , count);
        }
        return dp[sum] = minCount;
    }
    int numSquares(int n) {
        int sum = 0;
        memset(dp , -1 , sizeof(dp));
        return solve(sum , n);
    }
};