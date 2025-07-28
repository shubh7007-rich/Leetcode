class Solution {
public:
    void func(vector<int>& temp , vector<int>& nums , unordered_map<int , bool>& used , vector<vector<int>>& ans){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = 0 ; i < nums.size() ; i++){
            if(!used[nums[i]]){
                temp.push_back(nums[i]);
                used[nums[i]] = true;
                func(temp , nums , used , ans);
                used[nums[i]] = false;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // Approach 1 - extra space

        unordered_map<int , bool> used;

        for(int i : nums) used[i] = false;

        vector<int> temp;
        vector<vector<int>> ans;

        for(int i = 0 ; i < nums.size() ; i++){
            if(!used[nums[i]]){
                temp.push_back(nums[i]);
                used[nums[i]] = true;
                func(temp , nums , used , ans);
                used[nums[i]] = false;
                temp.pop_back();
            }
        }

        return ans;

    } 
};