class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin() , nums.end());
        int maxi = 1 , i = 1 , cnt = 1;
        while(i < nums.size()){
            if(nums[i] == nums[i-1] + 1){
                cnt++;
            }else if(nums[i] == nums[i-1]){
                
            }else{
                cnt = 1;
            }

            maxi = max(maxi , cnt);
            i++;
        }

        return maxi;
    }
};