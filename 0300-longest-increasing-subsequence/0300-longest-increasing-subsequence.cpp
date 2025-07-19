class Solution {
public:
    int dp[2501][2500];
    int func(int prev , int ind , vector<int>& nums , int n){
        if(ind >= n) return 0;

        int take = 0 , skip = 0;

        if(dp[prev + 1][ind] != -1) return dp[prev + 1][ind];

        if(prev == -1 || (nums[prev] < nums[ind])){
            take = 1 + func(ind , ind + 1 , nums ,  n);
        }

        skip = func(prev , ind + 1 , nums ,  n);

        return dp[prev + 1][ind] = max(skip , take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memset(dp , -1 , sizeof(dp));
        // int  maxi = 0;

        int maxi = func(-1 , 0 , nums , nums.size());
        

        return maxi;

    }
};