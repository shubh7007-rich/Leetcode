class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin() , nums.end());

        int maxi = 0;
        unordered_set<int> st(nums.begin() , nums.end());

        for(int i = 0 ; i < nums.size() ; i++){
            int tar = nums[i] + 1;

            if(st.find(tar) == st.end()) continue;

            int idx = upper_bound(nums.begin() , nums.end() , tar) - nums.begin() - 1;

            maxi = max(maxi , idx - i + 1);
        }

        return maxi;

    }
};