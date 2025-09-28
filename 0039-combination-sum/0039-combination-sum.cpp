class Solution {
public:
    void func(int ind , int sum ,vector<int>& nums , vector<int>& temp , vector<vector<int>>& ans , int target){
        if(sum == target){
                ans.push_back(temp);
                return;
            }
        if(ind >= nums.size()){
            
            return;
        }
        

        if(sum + nums[ind] <= target){
            temp.push_back(nums[ind]);
            func(ind , sum + nums[ind] ,nums , temp , ans , target);
            temp.pop_back();
        }
        func(ind + 1 , sum , nums , temp , ans , target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int sum = 0; 
        vector<int> temp;
        vector<vector<int>> ans;

        func(0 ,sum ,nums, temp , ans , target);

        return ans;
    }
};