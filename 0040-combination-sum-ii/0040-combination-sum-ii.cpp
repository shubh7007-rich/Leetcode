class Solution {
public:
    void func(int ind ,int sum ,vector<int> & temp , vector<vector<int>>& ans , vector<int>& nums , int target){
        if(ind >= nums.size()){
            if(sum == target){
                ans.push_back(temp);
            }
            return;
        }

        if(sum > target) return;

            temp.push_back(nums[ind]);
            sum += nums[ind];

            func(ind + 1 , sum , temp , ans , nums , target);
            sum -= nums[ind];
            temp.pop_back();
            while(ind + 1 < nums.size() && nums[ind] == nums[ind + 1]){
                ind++;
            }
        
        func(ind + 1, sum , temp , ans , nums , target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candi, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candi.begin() ,candi.end());
        func(0 ,0 , temp , ans , candi , target);
        return ans;
    }
};