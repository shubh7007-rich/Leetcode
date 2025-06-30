#define ll long long

class Solution {
public:
    int mod = 1e9 + 7;

    ll func(ll a, ll b) {
        ll res = 1;

        while(b){
            if(b&1){
                res = (a * res) % mod;
            }
            a = (a * a)%mod;
            b >>= 1;
        }

        return res;
    }
    int numSubseq(vector<int>& nums, int target) {
        ll ans = 0;

        sort(nums.begin() , nums.end());

        for(int i = 0 ; i < nums.size() ; i++){
            int tar = target - nums[i];

            int idx = upper_bound(nums.begin() , nums.end() , tar) - nums.begin() - 1;

            if(idx >= i)
                ans = (ans + (func(2 , idx - i)))%mod;
        }
        return ans;
    }
};