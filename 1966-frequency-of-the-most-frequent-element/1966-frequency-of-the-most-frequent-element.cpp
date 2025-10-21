#define ll long long
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        vector<ll> psum(n , 0);

        psum[0] = nums[0];

        for(int i = 1; i < n ; i++){
            psum[i] += psum[i-1] + nums[i];
        }

        int sum = 0 , i = 0 , ans = 0;

        for(int j = 0 ; j < n ; j++){
            // sum += nums[j];
            ll op = (j-i+1)* 1ll *nums[j];
            ll sum = (i == 0 ? psum[j] : psum[j] - psum[i-1]);

            ll req = op - sum;

            while(req > k){
                i++;
                op = (j-i+1)* 1ll * nums[j];
                sum = (i == 0 ? psum[j] : psum[j] - psum[i-1]);
                req = op - sum;
            }

            ans = max(ans , j-i+1);
        }

        return ans;
    }
};