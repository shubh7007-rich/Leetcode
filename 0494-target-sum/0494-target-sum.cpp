class Solution {
public:
    int dp[20][2001];

    int func(int ind , int sum, vector<int>& nums, int target){
        if(ind >= nums.size()){
            if(sum == target){
                return 1;
            }

            return 0;
        }

        if(dp[ind][sum + 1000] != -1) return dp[ind][sum + 1000];

        return dp[ind][sum + 1000] = func(ind + 1 , sum - nums[ind] , nums , target) + func(ind + 1 , sum + nums[ind] , nums , target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp , -1 , sizeof(dp));

        return func(0 , 0 , nums , target);
    }
};