class Solution {
public:
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;

        int n = nums.size();

        for(int num = 0 ; num < (1 << n) ; num++){
            vector<int> temp;
            for(int k = 0 ; k < n ; k++){
                if(num & (1 << k)){
                    temp.push_back(nums[k]);
                }
            }
            ans.push_back(temp);
        }

        return ans;

    }
};