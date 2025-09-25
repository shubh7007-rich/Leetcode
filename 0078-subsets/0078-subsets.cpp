class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> ans;
        for(int no = 0 ;  no < (1 << n) ; no++){
            vector<int> subset;

            for(int i = 0 ; i < n ; i++){
                if(no & (1 << i)){
                    subset.push_back(nums[i]);
                }
            }

            ans.push_back(subset);
        } 

        return ans;
    }
};