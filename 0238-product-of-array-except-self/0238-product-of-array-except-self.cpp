class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> ans(n , 0);

        int cnt0 = 0 ;

        vector<int> suffix(n , 1) , prefix(n , 1);
        suffix[n-1] = nums[n-1];
        prefix[0] = nums[0];

        cnt0 = (nums[0] == 0 ? 1 : 0);

        for(int i = 1 ; i < n ; i++){
            prefix[i] = prefix[i-1] * nums[i];
            if(nums[i] == 0) cnt0++;

            if(cnt0 > 1) return ans;
        }
        for(int i = n-2 ; i >= 0 ; i--){
            suffix[i] = suffix[i+1] * nums[i];
        }

        for(int i = 0 ; i < n ; i++){
            if(i == 0){
                ans[i] = suffix[1];
            }else if(i == n-1){
                ans[i] = prefix[i-1];
            }else{
                ans[i] = prefix[i-1] * suffix[i+1];
            }
        }

        return ans;

    }
}; 