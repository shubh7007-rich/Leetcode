class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ME = nums[0] , cnt = 1;

        // boyer-moore voting algo

        for(int i = 1 ; i < nums.size() ; i++){
            if(cnt == 0){
                ME = nums[i]; cnt = 1;
            }else if(nums[i] == ME){
                cnt++;
            }else{
                cnt--;
            }
        }

        // as here majority element always exists , so we don't need to verify

        return ME;
    }
};