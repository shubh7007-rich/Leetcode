class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int precnt = 0 , cnt = 1 , ans = 0;

        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] > nums[i-1]){
                cnt++;
            }else{
                precnt = cnt;
                cnt = 1;
            }

            ans = max(ans , min(precnt , cnt));
            ans = max(ans , cnt/2);
        }

        return ans;
    }
};