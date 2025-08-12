class Solution {
public:
    int mod = 1e9 + 7;
    int dp[350][350];
    int func(int ind , int sum , int n , int x , vector<int>& nums){
        if(sum == n) return 1;

        if(sum > n || ind >= nums.size()) return 0;

        if(dp[ind][sum] != -1) return dp[ind][sum];

        long a = pow(nums[ind] , x);

        int take = 0;
        if(sum + a <= n) take = func(ind + 1, sum + a , n , x, nums) % mod;

        int notTake = func(ind + 1 , sum , n , x, nums) % mod;

        return dp[ind][sum] = (take + notTake) % mod;
    }
    int numberOfWays(int n, int x) {
        vector<int> nums;

        if(n == 1) return 1;

        for(int i = 1 ; i <= 300 ; i++) nums.push_back(i);

        memset(dp , -1 , sizeof(dp));

        return func(0 , 0 , n , x , nums);
    }
};