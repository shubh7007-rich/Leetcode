class Solution {
public:
    int inf = 1e7;
    int dp[100][10000];
    int func(int ind , int sum , vector<int>& psq , int n){
        if(sum == n) return 0;

        if(sum > n || ind >= psq.size()) return inf;
        
        if(dp[ind][sum] != -1) return dp[ind][sum];

        int take = 1 + func(ind , sum + psq[ind] , psq , n);
        int notTake = func(ind+1, sum , psq , n);

        return dp[ind][sum] = min(take , notTake);
    }
    int numSquares(int n) {
        vector<int> psq;

        memset(dp , -1 , sizeof(dp));

        for(int i = 1 ; i*i <= n ; i++){
            psq.push_back(i*i);
        }
        
        return func(0 , 0 , psq , n);
    }
};