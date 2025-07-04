#define ll long long
class Solution {
public:
    int mod = 1e9 + 7;

    // int power(int a , int b){
    //     ll result = 1;
    //     while(b){
    //         if(b&1){
    //             result = (result * a) % mod;
    //         }
    //         a = (a * 1ll * a) % mod;
    //         b >>= 1;
    //     }

    //     return result % mod;
    // }
    int numSubseq(vector<int>& nums, int target) {
        int cnt = 0;
        int n = nums.size();

        vector<ll> power(n , 1);
        ll a = 2;
        for(int i = 1; i < n ; i++){
            power[i] = a;
            a = (a*2)%mod;
        }

        sort(nums.begin() , nums.end());

        for(int i = 0 ; i < nums.size() ; i++){
            int tar = target - nums[i];

            int idx = upper_bound(nums.begin() , nums.end() , tar) - nums.begin() - 1;

            if( idx >= i ) cnt = (cnt + power[idx-i])%mod;
        }

        // for(ll & i : power) cout << i << " ";

        return cnt;
    }
};