class Solution {
public:
    int mod = 1e9 + 7;

    int dp[30][900];

    int func(int ind , int sum , int n , int k , int target){
        if(ind >= n){
            if(sum == target){
                return 1;
            }

            return 0;
        }
        if(dp[ind][sum] != -1) return dp[ind][sum];

        int totalways = 0;
        for(int i = 1; i <= k ; i++){
            sum += i;
            totalways = (totalways + func(ind + 1 , sum , n , k , target)) % mod;
            sum -= i;
        }

        return dp[ind][sum] = totalways;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp , -1 , sizeof(dp));
        return func(0 , 0 , n , k , target);
    }
};