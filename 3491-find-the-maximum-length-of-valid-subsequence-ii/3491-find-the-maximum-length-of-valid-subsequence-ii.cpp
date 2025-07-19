class Solution {
public:
    // int dp[1002][1001];
    // int func(int prev , int ind , vector<int>& nums , int k ,int rem){
    //     if(ind >= nums.size()) return 0;

    //     if(dp[prev+1][ind] != -1) return dp[prev+1][ind];

    //     int take = 0 , skip = 0;
    //     if(prev == -1 || ((nums[ind] + nums[prev]) % k == mod)){
    //         take = 1 + func(ind , ind+1 , nums , k , mod);
    //     }

    //     skip = func(prev , ind+1 , nums , k , mod);

    //     return dp[prev + 1][ind] = max(take , skip);
    // }
    // int func(vector<int>& nums, int mod , int n , int k){
    //     vector<int> dp(n , 1);  // filling dp array with 1 as there is no previous element to violate the rule
    //     int maxi = 0;

    //     for(int i = 1 ; i < n ; i++){
    //         for(int j = 0 ; j < i ; j++){
    //             if((nums[i] + nums[j]) % k == mod){
    //                 dp[i] = max(dp[i] , 1 + dp[j]);
    //                 maxi = max(maxi , dp[i]);
    //             }
    //         }
    //     }

    //     return maxi;
    // }
    int maximumLength(vector<int>& nums, int k) {

        /* rem --> remainder

        here you calling for every value for 0 to k-1 , but that is very inefficent and give TLE as
        for example if we calling for mod = 3 , so it will only store when (nums[i] + nums[j]) % k == rem
        and skip all other cases which is inefficent , so instead store for all the remainders by making 
        a 2d array dp[remainder][i] , so whatever remainder is coming store for that index


        */
        // int maxi = 0 , n = nums.size();
        // for(int rem = 0 ; rem < k ; rem++){    // u don't have to call it for k times 
        //     // memset(dp , -1 , sizeof(dp));
        //     // maxi = max(maxi , func(-1 , 0 , nums , k , mod));
        //     maxi = max(maxi , func(nums , rem , n , k));
        // }

        int n = nums.size() ,maxi = 0;
        vector<vector<int>> dp(k , vector<int>(n , 1));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                int rem = (nums[i] + nums[j]) % k;

                dp[rem][i] = max(dp[rem][i] , 1 + dp[rem][j]);

                maxi = max(maxi , dp[rem][i]);
            }
        }

        return maxi;
    }
};