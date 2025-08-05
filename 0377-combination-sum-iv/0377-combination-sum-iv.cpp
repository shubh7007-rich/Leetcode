class Solution {
public:
    int dp[20000];
    int func(int sum , vector<int>& nums , int target){
        if(sum > target) return 0;
        if(sum == target) return 1;

        int ways = 0;

        if(dp[sum] != -1) return dp[sum];

        for(int i = 0 ; i < nums.size() ; i++){
            if(sum + nums[i] <= target){
                ways += func(sum + nums[i] , nums , target);
            }
        }

        return dp[sum] = ways;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp , -1 , sizeof(dp));
        
        return func( 0 , nums , target);
    }
};