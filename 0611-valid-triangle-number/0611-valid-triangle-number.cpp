class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size() , ans = 0;
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0) continue;
            for(int j = i+1 ; j < n ; j++){
                if(nums[j] == 0) continue;
                int sum = nums[i] + nums[j];
                int idx = lower_bound(nums.begin() , nums.end() , sum) - nums.begin() - 1;

                if(idx > j){
                    ans += (idx - j);
                }else if(idx < j && idx > i){
                    ans += idx - i;
                }
            }
        }

        return ans;
    }
}; 