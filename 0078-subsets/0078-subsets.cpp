class Solution {
public:
    void func(int ind , vector<int>& temp , vector<int>& nums ,vector<vector<int>>& ans){
        if(ind >= nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        func(ind + 1 , temp , nums , ans);
        temp.pop_back();
        func(ind + 1 , temp , nums , ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;

        func(0 , temp , nums , ans);

        return ans;
    }
};