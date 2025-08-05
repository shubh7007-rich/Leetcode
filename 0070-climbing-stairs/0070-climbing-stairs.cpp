class Solution {
public:
    int dp[46];

    int func(int i , int n){
        if(i == n) return 1;

        if(i > n) return 0;

        if(dp[i] != -1) return dp[i];

        int take1 =  func(i+1 , n);
        int take2 =  func(i+2 , n);

        return dp[i] = take1 + take2;
    }
    int climbStairs(int n) {
        memset(dp , -1 , sizeof(dp));
        return func(0 , n);
    }
};