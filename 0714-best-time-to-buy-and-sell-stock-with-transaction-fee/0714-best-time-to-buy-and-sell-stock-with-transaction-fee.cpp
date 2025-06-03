class Solution {
public:
    int dp[50001][2];
    int func(int ind , int prev , int n , vector<int>& prices, int fee){
        if(ind >= n) return 0;

        int ans = 0;

        if(dp[ind][prev] != -1) return dp[ind][prev];

        if(!prev){
            ans = max(-1*prices[ind] + func(ind+1 , !prev , n , prices , fee) , func(ind+1 , prev , n , prices , fee));
        }else{
            ans = max(prices[ind] + func(ind+1 , !prev , n , prices , fee) - fee , func(ind+1 , prev , n , prices , fee));
        }

        return dp[ind][prev] = ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        memset(dp , - 1, sizeof(dp));
        return func(0 , 0 , n , prices , fee);
    }
};