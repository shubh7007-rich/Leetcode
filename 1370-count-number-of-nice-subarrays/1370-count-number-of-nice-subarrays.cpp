class Solution {
public:
    int func(vector<int>& nums, int goal) {
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
    int numberOfSubarrays(vector<int>& nums, int k) {
        int o = 0 , i = 0 , cnt = 0;

        for(int & num : nums){
            if(num&1){
                num = 1;
            }else{
                num = 0;
            }
        }

        return func(nums , k);
    }
};