class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int i = 0;  // start of the window
        int n = nums.size() , sum = 0 , maxi = INT_MIN;

        for(int j = 0 ; j < n ; j++){
            sum += nums[j];

            while(i < j && (nums[i] < 0 || sum < 0)){
                sum -= nums[i];

                i++;
            }

            maxi = max(sum , maxi);
        }

        return maxi;
    }
};