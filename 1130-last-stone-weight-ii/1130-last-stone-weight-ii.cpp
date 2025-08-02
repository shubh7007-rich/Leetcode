class Solution {
public:
    int inf = 1e7;

    int dp[30][3001];

    int func(int ind , int sum , vector<int>& stones , int target , int total){
        if(sum >= target){
            return sum - (total - sum);
        }

        if(ind >= stones.size()) return inf;

        if(dp[ind][sum] != -1) return dp[ind][sum];

        int take = func(ind + 1 , sum + stones[ind] ,stones, target , total);
        int notTake = func(ind + 1 , sum ,stones, target , total);

        return dp[ind][sum] = min(take , notTake);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int total = accumulate(stones.begin() , stones.end() , 0);

        int target = ceil(float(total)/2);

        memset(dp , -1 , sizeof(dp));

        int sum = 0;

        return func(0 , sum , stones , target , total);
    }
}; 