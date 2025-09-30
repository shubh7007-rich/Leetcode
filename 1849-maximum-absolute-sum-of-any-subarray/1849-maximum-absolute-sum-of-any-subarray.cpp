class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size() , sum = 0 , maxi = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];

            maxi = max(maxi , abs(sum));

            if(sum < 0){
                sum = 0;
            }
        }
        sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];

            maxi = max(maxi , abs(sum));

            if(sum > 0){
                sum = 0;
            }
        }

        return maxi;
    }
};