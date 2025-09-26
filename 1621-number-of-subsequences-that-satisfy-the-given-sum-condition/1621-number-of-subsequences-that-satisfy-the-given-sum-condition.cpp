#define ll long long
class Solution {
public:
    int mod = 1e9 + 7;

    ll power(ll a , ll b){
        ll res = 1;

        while(b){
            if(b&1){
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b = b >> 1;
        }

        return res;

    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int cnt = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            int num = nums[i];

            if(num > target) break;

            int toFind = target - num;

            int idx = upper_bound(nums.begin() , nums.end() , toFind) - nums.begin() - 1;

            if(idx >= i){
                cnt = (cnt + (power(2 , idx - i))) % mod;
            }
        }

        return cnt;
    }
};