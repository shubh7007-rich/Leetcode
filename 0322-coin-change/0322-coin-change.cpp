#define ll long long
class Solution {
public:
    int inf = 1e9;
    int dp[12][10001];
    
    int coin(int ind , ll sum , vector<int>& coins, int amount){
        if(sum == amount) return 0;

        if(sum > amount || ind >= coins.size()) return inf;

        if(dp[ind][sum] != -1) return dp[ind][sum];
    
        ll take = 1 + coin(ind , sum + coins[ind], coins , amount);
        
        ll notTake = coin(ind + 1 , sum  , coins , amount);

        return dp[ind][sum] = min(take , notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp , -1 , sizeof(dp));
        ll x = coin(0 , 0 , coins , amount);
        return (x == inf) ? -1 : x;
    }
};