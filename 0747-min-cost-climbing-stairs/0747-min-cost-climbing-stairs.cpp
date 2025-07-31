class Solution {
public:
    int dp[1000];
    int func(int ind , vector<int>& cost){
        if(ind >= cost.size()) return 0;

        if(dp[ind] != -1) return dp[ind];

        int oneStep = cost[ind] + func(ind + 1 , cost);
        int twoStep = cost[ind] + func(ind + 2 , cost);

        return dp[ind] = min(oneStep , twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp , -1 , sizeof(dp));

        return min(func(0 , cost) , func(1 , cost));
    }
};