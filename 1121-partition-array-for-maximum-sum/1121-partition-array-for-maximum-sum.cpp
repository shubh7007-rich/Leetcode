class Solution {
public:
    int dp[500];

    int func(int ind ,vector<int>& arr, int k){
        if(ind >= arr.size()) return 0;

        int maxi = arr[ind];

        int maxiSum = 0;

        if(dp[ind] != -1) return dp[ind];

        for(int i = ind ; i < arr.size() && i < ind + k ; i++){
            maxi = max(maxi , arr[i]);

            maxiSum = max(maxiSum , (i+1-ind)*maxi + func(i+1 , arr , k));
        }

        return dp[ind] = maxiSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int maxi = arr[0];
        int maxiSum = 0;
        memset(dp , -1 , sizeof(dp));

        for(int i = 0 ; i < k ; i++){
            maxi = max(maxi , arr[i]);
            maxiSum = max(maxiSum , (i+1)*maxi + func(i+1 , arr , k));
        }

        return maxiSum;
    }
};