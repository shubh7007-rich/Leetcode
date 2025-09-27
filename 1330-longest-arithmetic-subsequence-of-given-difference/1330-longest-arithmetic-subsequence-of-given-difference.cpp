class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int , int> dp;

        int maxi = 0;

        for(int x : arr){
            int prev = x - diff;

            if(dp.count(prev)){
                dp[x] = max(dp[x] , 1 + dp[prev]);
            }else{
                dp[x] = 1;
            }

            maxi = max(dp[x] , maxi);
        }

        return maxi;
    }
};