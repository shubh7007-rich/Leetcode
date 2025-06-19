class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int n = nums.size() , i = 0 , cnt = 0;
        while(i < n){
            int target = nums[i] + k;

            auto it = upper_bound(nums.begin() , nums.end() , target) - nums.begin();
            cnt++;
            i = it;
        }

        return cnt;
    }
};