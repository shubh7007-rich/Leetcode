class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int me = nums[0] , cnt = 1;

        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] == me){
                cnt++;
            }else if(cnt == 0){
                me = nums[i];
                cnt = 1;
            }else{
                cnt--;
            }
        }

        return me;
    }
};