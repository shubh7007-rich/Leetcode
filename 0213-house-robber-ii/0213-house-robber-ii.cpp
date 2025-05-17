class Solution {
public:
    int dp[101];
    int func(int ind , int n , vector<int>& nums){
        if(ind >= n) return 0;

        if(dp[ind] != -1) return dp[ind];

        int take = nums[ind] + func(ind+2 , n , nums);

        int noTake = func(ind+1 , n , nums);

        return dp[ind] = max(take , noTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        memset(dp , -1 , sizeof(dp));

        int ans = func(0 , n-1 , nums);

        memset(dp , -1 , sizeof(dp));
        int ans2 = func(1 , n , nums);

        return max(ans , ans2);
    }
};