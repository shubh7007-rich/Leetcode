class Solution {
public:
    map<int , int> dp;
    int func(int ind , int sum, vector<int>& nums, int target){
        if(ind >= nums.size()){
            if(sum == target){
                return 1;
            }

            return 0;
        }

        // if(dp.find())

        return func(ind + 1 , sum - nums[ind] , nums , target) + func(ind + 1 , sum + nums[ind] , nums , target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return func(0 , 0 , nums , target);
    }
};