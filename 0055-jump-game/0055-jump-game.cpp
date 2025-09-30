class Solution {
public:
    bool canJump(vector<int>& nums) {
        int yo = 0;

        for(int i = 0; i < nums.size()-1; i++){
            yo = max(yo , nums[i]);

            if(yo == 0) return false;

            yo--;
        }

        return true;
    }
};