class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int  mini = nums[0] , maxDiff = INT_MIN;

        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] - mini > 0){
                maxDiff = max(maxDiff , nums[i] - mini);
            }
            mini = min(nums[i] , mini);
        }

        return (maxDiff == INT_MIN) ? -1 : maxDiff;
    }
};