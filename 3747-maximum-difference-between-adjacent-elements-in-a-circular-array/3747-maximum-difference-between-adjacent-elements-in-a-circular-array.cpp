class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size() , maxi = 0;
        for(int i = 0 ; i < n ; i++){
            int nxt = (i+1)%n;

            maxi = max(maxi , abs(nums[nxt] - nums[i]));
        }

        return maxi;
    }
};