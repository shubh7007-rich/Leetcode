#define ll long long
class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<ll> power;
        // we don't need to create the power array this way , as we know that a number  in binary form is basically written in minimum number of powers of 2

        // ll sum = 0;
        // while(sum < n){
        //     int a = 1;
        //     while(sum + (2*a) <= n){
        //         a = (a * 2) % mod;
        //     }

        //     sum += a;
        //     power.push_back(a);
        // }

        for(int k = 0 ; k < 32 ; k++){
            if(n & (1 << k)){
                power.push_back(1 << k);
            }
        }

        sort(power.begin() , power.end());

        vector<int> ans;

        for(vector<int> arr : queries){
            int left = arr[0] , right = arr[1];

            int a = 1;

            for(int i = left ; i <= right ; i++){
                a = (a * power[i]) % mod;
            }

            ans.push_back(a);
        }

        return ans;
    }
};