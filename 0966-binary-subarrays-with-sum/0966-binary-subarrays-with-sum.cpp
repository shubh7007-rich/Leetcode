class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i = 0 , z = 0 , sum = 0 , cnt = 0;

        for(int j = 0 ; j < nums.size() ; j++){
            sum += nums[j];

            while(i < j  && (sum > goal  || nums[i] == 0)){
                sum -= nums[i];

                if(nums[i] == 0){
                    z++;
                }else{
                    z = 0;
                }
                i++;
            }

            if(sum == goal) cnt += 1 + z;
        }

        return cnt;
    }
};