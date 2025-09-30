class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0 , n = nums.size() , maxi = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];

            maxi = max(sum , maxi);
            
            if(sum < 0){
                sum = 0;
            }
        }

        return maxi;
    }
};