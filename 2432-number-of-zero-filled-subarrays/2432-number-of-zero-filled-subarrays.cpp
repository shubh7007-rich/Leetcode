#define ll long long
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ll cnt = 0 , cnt0 = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0){
                cnt += 1 + cnt0;
                cnt0++;
            }else{
                cnt0 = 0;
            }
        }

        return cnt;
    }
};