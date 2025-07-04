#define ll long long
class Solution {
public:
    int mod = 1e9 + 7;

    int power(int a , int b){
        ll result = 1;
        while(b){
            if(b&1){
                result = (result * a) % mod;
            }
            a = (a * 1ll * a) % mod;
            b >>= 1;
        }

        return result % mod;
    }
    int numSubseq(vector<int>& nums, int target) {
        int cnt = 0;

        sort(nums.begin() , nums.end());

        for(int i = 0 ; i < nums.size() ; i++){
            int tar = target - nums[i];

            int idx = upper_bound(nums.begin() , nums.end() , tar) - nums.begin() - 1;

            if( idx >= i ) cnt = (cnt +  power(2 , idx - i))%mod;
        }

        return cnt;
    }
};